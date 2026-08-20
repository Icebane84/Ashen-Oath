// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Soul/AshenImprintBufferComponent.h"
#include "Soul/AshenSoulConstellationSubsystem.h"
#include "Engine/GameInstance.h"

UAshenImprintBufferComponent::UAshenImprintBufferComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	// Pre-reserve contiguous block per ENGINE-SPEC-001
	ImprintBuffer.Reserve(64);
}

void UAshenImprintBufferComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenImprintBufferComponent::AddImprint(FAshenPsychologicalImprint Imprint)
{
	if (ImprintBuffer.Num() >= 64)
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenImprintBufferComponent: Imprint buffer at capacity (64). Auto-flushing to kernel."));
		FlushToKernel();
	}
	ImprintBuffer.Add(Imprint);
	BufferedImprintCount = ImprintBuffer.Num();
	UE_LOG(LogTemp, Verbose, TEXT("UAshenImprintBufferComponent: Imprint '%s' added (Buffer: %d/64, DebtDelta: %f)"),
		*Imprint.ImprintID.ToString(), BufferedImprintCount, Imprint.IntegrationDebtDelta);
}

void UAshenImprintBufferComponent::FlushToKernel()
{
	if (ImprintBuffer.Num() == 0) return;

	UGameInstance* GI = GetOwner() ? GetOwner()->GetGameInstance() : nullptr;
	if (!GI) return;

	UAshenSoulConstellationSubsystem* Kernel = GI->GetSubsystem<UAshenSoulConstellationSubsystem>();
	if (!Kernel)
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenImprintBufferComponent: SoulConstellationSubsystem not found. Flush aborted."));
		return;
	}

	float TotalStance = 0.0f, TotalEmpathic = 0.0f, TotalTactical = 0.0f, TotalDebt = 0.0f;
	for (const FAshenPsychologicalImprint& Imp : ImprintBuffer)
	{
		TotalStance   += Imp.StanceWeightDelta;
		TotalEmpathic += Imp.EmpathicWeightDelta;
		TotalTactical += Imp.TacticalWeightDelta;
		TotalDebt     += Imp.IntegrationDebtDelta;
	}

	Kernel->ApplyRawWeightDeltas(TotalStance, TotalEmpathic, TotalTactical, TotalDebt);
	Kernel->KernelIdentityState.TotalImprintsProcessed += ImprintBuffer.Num();

	ImprintBuffer.Reset();
	BufferedImprintCount = 0;

	UE_LOG(LogTemp, Log, TEXT("UAshenImprintBufferComponent: Flushed %d imprints to Soul Constellation Kernel (TotalDebt flushed: %f)"),
		Kernel->KernelIdentityState.TotalImprintsProcessed, TotalDebt);
}

float UAshenImprintBufferComponent::GetPendingDebtAccumulation() const
{
	float Total = 0.0f;
	for (const FAshenPsychologicalImprint& Imp : ImprintBuffer)
		Total += Imp.IntegrationDebtDelta;
	return Total;
}
