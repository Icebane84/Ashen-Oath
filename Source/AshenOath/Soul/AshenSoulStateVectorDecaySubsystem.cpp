// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Soul/AshenSoulStateVectorDecaySubsystem.h"
#include "Soul/AshenSoulConstellationSubsystem.h"
#include "Engine/GameInstance.h"

void UAshenSoulStateVectorDecaySubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenSoulStateVectorDecaySubsystem: Temporal decay subsystem initialized (DecayCoeff=%f)."), DecayCoefficient);
}

void UAshenSoulStateVectorDecaySubsystem::Deinitialize() { Super::Deinitialize(); }

void UAshenSoulStateVectorDecaySubsystem::ApplyTemporalDecay(float SessionDeltaHours)
{
	UGameInstance* GI = GetWorld() ? GetWorld()->GetGameInstance() : nullptr;
	if (!GI) return;
	UAshenSoulConstellationSubsystem* Kernel = GI->GetSubsystem<UAshenSoulConstellationSubsystem>();
	if (!Kernel) return;

	const float DecayFactor = FMath::Clamp(1.0f - (DecayCoefficient * SessionDeltaHours), 0.5f, 1.0f);
	Kernel->KernelIdentityState.StanceWeight   = FMath::Lerp(0.5f, Kernel->KernelIdentityState.StanceWeight,   DecayFactor);
	Kernel->KernelIdentityState.EmpathicWeight = FMath::Lerp(0.5f, Kernel->KernelIdentityState.EmpathicWeight, DecayFactor);
	Kernel->KernelIdentityState.TacticalWeight = FMath::Lerp(0.5f, Kernel->KernelIdentityState.TacticalWeight, DecayFactor);
	UE_LOG(LogTemp, Log, TEXT("UAshenSoulStateVectorDecaySubsystem: Temporal decay applied (DeltaHours=%f, DecayFactor=%f)."), SessionDeltaHours, DecayFactor);
}
