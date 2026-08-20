// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenNightmareIncursionSubsystem.h"

void UAshenNightmareIncursionSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	CurrentIncursionState.IncursionIntensity = 0.0f;
	CurrentIncursionState.bIsIncursionActive = false;
	CurrentIncursionState.ActiveRiftCount = 0;
	CurrentIncursionState.RealityStabilityIndex = 1.0f;
	UE_LOG(LogTemp, Log, TEXT("UAshenNightmareIncursionSubsystem: Nightmare Incursion Subsystem initialized."));
}
void UAshenNightmareIncursionSubsystem::Deinitialize() { Super::Deinitialize(); }

bool UAshenNightmareIncursionSubsystem::EvaluateIncursionTrigger(float CurrentIntegrationDebt)
{
	const bool bTriggered = CurrentIntegrationDebt >= 0.75f;
	if (bTriggered && !CurrentIncursionState.bIsIncursionActive)
	{
		CurrentIncursionState.bIsIncursionActive = true;
		CurrentIncursionState.IncursionIntensity = FMath::Clamp((CurrentIntegrationDebt - 0.75f) / 0.25f, 0.1f, 1.0f);
		CurrentIncursionState.RealityStabilityIndex = 1.0f - CurrentIncursionState.IncursionIntensity;
		UE_LOG(LogTemp, Warning, TEXT("UAshenNightmareIncursionSubsystem: NIGHTMARE INCURSION TRIGGERED! (Debt: %.2f >= 0.75, Intensity: %.2f)"),
			CurrentIntegrationDebt, CurrentIncursionState.IncursionIntensity);
	}
	else if (!bTriggered && CurrentIncursionState.bIsIncursionActive)
	{
		CurrentIncursionState.bIsIncursionActive = false;
		CurrentIncursionState.IncursionIntensity = 0.0f;
		CurrentIncursionState.RealityStabilityIndex = 1.0f;
		UE_LOG(LogTemp, Log, TEXT("UAshenNightmareIncursionSubsystem: Nightmare Incursion subsided (Debt: %.2f < 0.75)."), CurrentIntegrationDebt);
	}
	return CurrentIncursionState.bIsIncursionActive;
}

void UAshenNightmareIncursionSubsystem::SetIncursionIntensity(float Intensity)
{
	CurrentIncursionState.IncursionIntensity = FMath::Clamp(Intensity, 0.0f, 1.0f);
	CurrentIncursionState.bIsIncursionActive = CurrentIncursionState.IncursionIntensity > 0.0f;
	CurrentIncursionState.RealityStabilityIndex = 1.0f - CurrentIncursionState.IncursionIntensity;
}

void UAshenNightmareIncursionSubsystem::RegisterRift(bool bOpened)
{
	if (bOpened) CurrentIncursionState.ActiveRiftCount++;
	else CurrentIncursionState.ActiveRiftCount = FMath::Max(0, CurrentIncursionState.ActiveRiftCount - 1);

	UE_LOG(LogTemp, Log, TEXT("UAshenNightmareIncursionSubsystem: Active Rift count is now %d."), CurrentIncursionState.ActiveRiftCount);
}
