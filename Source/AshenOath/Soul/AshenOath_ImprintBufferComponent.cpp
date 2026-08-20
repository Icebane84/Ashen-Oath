// AshenOath_ImprintBufferComponent.cpp
// Copyright Ashen Oath. All rights reserved.
#include "AshenOath_ImprintBufferComponent.h"
#include "AshenSoulConstellationSubsystem.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"

DEFINE_LOG_CATEGORY(LogAshenImprint);


UAshenOath_ImprintBufferComponent::UAshenOath_ImprintBufferComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenOath_ImprintBufferComponent::BeginPlay()
{
	Super::BeginPlay();
	ImprintBuffer.Reserve(MaxImprintCapacity);
}

void UAshenOath_ImprintBufferComponent::AddImprint(EImprintType Type, float Weight)
{
	if (Weight <= 0.0f)
	{
		return;
	}

	// FIFO eviction when at capacity -- oldest unprocessed imprint discarded.
	if (ImprintBuffer.Num() >= MaxImprintCapacity)
	{
		ImprintBuffer.RemoveAt(0, 1, EAllowShrinking::No);
		UE_LOG(LogAshenImprint, Warning, TEXT("ImprintBuffer at capacity (%d). Evicting oldest imprint."), MaxImprintCapacity);
	}

	FPsychologicalImprint NewImprint;
	NewImprint.Type      = Type;
	NewImprint.Weight    = FMath::Clamp(Weight, 0.0f, 1.0f);
	NewImprint.Timestamp = GetWorld() ? GetWorld()->GetTimeSeconds() : 0.0f;
	ImprintBuffer.Add(NewImprint);

	// Accumulate debt scaled by designer weight. Clamp to [0, 1].
	IntegrationDebt = FMath::Clamp(IntegrationDebt + (NewImprint.Weight * DebtWeightScale), 0.0f, 1.0f);

	EvaluateAndBroadcastStageChange();
}

void UAshenOath_ImprintBufferComponent::DecayBuffer()
{
	// Wipe the imprint array -- no permanent state change, just session reset.
	ImprintBuffer.Reset();

	// Partial debt relief: player loses some pressure but not all (unresolved trauma remains).
	IntegrationDebt = FMath::Clamp(IntegrationDebt - DecayOnDeathFraction, 0.0f, 1.0f);

	UE_LOG(LogAshenImprint, Log, TEXT("ImprintBuffer decayed on death. IntegrationDebt now: %.2f"), IntegrationDebt);

	EvaluateAndBroadcastStageChange();
}

TArray<FPsychologicalImprint> UAshenOath_ImprintBufferComponent::ConsumeBuffer()
{
	TArray<FPsychologicalImprint> Consumed = MoveTemp(ImprintBuffer);

	// Full reset -- successful integration clears all pressure.
	ImprintBuffer.Reserve(MaxImprintCapacity);
	IntegrationDebt = 0.0f;

	UE_LOG(LogAshenImprint, Log, TEXT("ImprintBuffer consumed: %d imprints integrated. IntegrationDebt reset to 0."), Consumed.Num());

	EvaluateAndBroadcastStageChange();

	return Consumed;
}

EIntegrationDebtStage UAshenOath_ImprintBufferComponent::GetDebtStage() const
{
	if (IntegrationDebt >= 1.0f)  return EIntegrationDebtStage::ForcedCollapse;
	if (IntegrationDebt >= 0.75f) return EIntegrationDebtStage::RuntimeNoise;
	if (IntegrationDebt >= 0.5f)  return EIntegrationDebtStage::MemoryBleed;
	return EIntegrationDebtStage::Dormant;
}

EImprintType UAshenOath_ImprintBufferComponent::GetDominantImprintType() const
{
	// Tally weight per type, return the heaviest.
	TMap<EImprintType, float> WeightMap;

	for (const FPsychologicalImprint& Imprint : ImprintBuffer)
	{
		float& Accumulated = WeightMap.FindOrAdd(Imprint.Type);
		Accumulated += Imprint.Weight;
	}

	EImprintType DominantType   = EImprintType::Combat;
	float        HighestWeight  = -1.0f;

	for (const TPair<EImprintType, float>& Pair : WeightMap)
	{
		if (Pair.Value > HighestWeight)
		{
			HighestWeight = Pair.Value;
			DominantType  = Pair.Key;
		}
	}

	return DominantType;
}

void UAshenOath_ImprintBufferComponent::EvaluateAndBroadcastStageChange()
{
	const EIntegrationDebtStage CurrentStage = GetDebtStage();
	if (CurrentStage != CachedDebtStage)
	{
		UE_LOG(LogAshenImprint, Log, TEXT("Integration Debt stage transition: %d -> %d (Debt: %.2f)"),
			static_cast<int32>(CachedDebtStage),
			static_cast<int32>(CurrentStage),
			IntegrationDebt);

		OnDebtStageChanged.Broadcast(CachedDebtStage, CurrentStage);

		// ENGINE-SPEC-001 Section 2: Debt = 1.0 (ForcedCollapse) triggers involuntary Mindscape collapse
		if (CurrentStage == EIntegrationDebtStage::ForcedCollapse)
		{
			if (UWorld* World = GetWorld())
			{
				if (UGameInstance* GI = World->GetGameInstance())
				{
					if (UAshenSoulConstellationSubsystem* Kernel = GI->GetSubsystem<UAshenSoulConstellationSubsystem>())
					{
						UE_LOG(LogAshenImprint, Warning, TEXT("IntegrationDebt reached 1.0 (ForcedCollapse)! Triggering involuntary Mindscape entry."));
						Kernel->InvokeIntegration(/*bForced=*/true);
					}
				}
			}
		}

		CachedDebtStage = CurrentStage;
	}
}

