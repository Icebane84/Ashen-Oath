// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "AI/AshenDualSenseTacticalAIDirectorComponent.h"

UAshenDualSenseTacticalAIDirectorComponent::UAshenDualSenseTacticalAIDirectorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenDualSenseTacticalAIDirectorComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenDualSenseTacticalAIDirectorComponent::NotifyPostureBreakOpportunity(FName MonsterID)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenDualSenseTacticalAIDirectorComponent: Posture Break Opportunity on %s -> Triggered DualSense Tactical Prompt."),
		*MonsterID.ToString());
}
