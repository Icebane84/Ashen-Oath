// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "AI/AshenShepherdsGambitAIDirectorComponent.h"

UAshenShepherdsGambitAIDirectorComponent::UAshenShepherdsGambitAIDirectorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenShepherdsGambitAIDirectorComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenShepherdsGambitAIDirectorComponent::CoordinateCompanionContainment(EUnchainedHazardLevel HazardLevel)
{
	if (HazardLevel == EUnchainedHazardLevel::Catastrophic)
	{
		UE_LOG(LogTemp, Error, TEXT("UAshenShepherdsGambitAIDirectorComponent: CATASTROPHIC CRISIS -> Garrett forming kinetic wall in front of Serafina!"));
	}
	else if (HazardLevel == EUnchainedHazardLevel::Hazardous)
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenShepherdsGambitAIDirectorComponent: HAZARDOUS -> Garrett preparing Gloomwood needles while Serafina monitors burnout."));
	}
}
