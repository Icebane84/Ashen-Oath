// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "AI/AshenShepherdsGambitSubsystem.h"

void UAshenShepherdsGambitSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	bIsUnchainedContainmentActive = false;
	CurrentHazardLevel = EUnchainedHazardLevel::Safe;
	UE_LOG(LogTemp, Log, TEXT("UAshenShepherdsGambitSubsystem: Shepherd's Gambit Containment Subsystem initialized."));
}
void UAshenShepherdsGambitSubsystem::Deinitialize() { Super::Deinitialize(); }

void UAshenShepherdsGambitSubsystem::EvaluateCorruptionThreshold(float CorruptionAmount)
{
	const float C = FMath::Clamp(CorruptionAmount, 0.0f, 1.0f);

	if (C >= 0.90f)
	{
		CurrentHazardLevel = EUnchainedHazardLevel::Catastrophic;
		bIsUnchainedContainmentActive = true;
		UE_LOG(LogTemp, Error, TEXT("UAshenShepherdsGambitSubsystem: CATASTROPHIC UNCHAINED HAZARD (C: %.2f)! Kaelen is Target-Blind!"), C);
	}
	else if (C >= 0.70f)
	{
		CurrentHazardLevel = EUnchainedHazardLevel::Hazardous;
		bIsUnchainedContainmentActive = true;
		UE_LOG(LogTemp, Warning, TEXT("UAshenShepherdsGambitSubsystem: THE SHEPHERD'S GAMBIT ACTIVATED (C: %.2f)! Companion AI Pivoted to Containment!"), C);
	}
	else
	{
		CurrentHazardLevel = EUnchainedHazardLevel::Safe;
		bIsUnchainedContainmentActive = false;
	}
}

void UAshenShepherdsGambitSubsystem::ResolveContainmentCrisis()
{
	bIsUnchainedContainmentActive = false;
	CurrentHazardLevel = EUnchainedHazardLevel::Safe;
	UE_LOG(LogTemp, Warning, TEXT("UAshenShepherdsGambitSubsystem: Containment Crisis Resolved! Standard Three-Legged Stool Cooperation Restored."));
}
