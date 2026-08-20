// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "AI/AshenTacticalPerkCompanionAIDirectorComponent.h"

UAshenTacticalPerkCompanionAIDirectorComponent::UAshenTacticalPerkCompanionAIDirectorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenTacticalPerkCompanionAIDirectorComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenTacticalPerkCompanionAIDirectorComponent::TriggerCompanionWeakpointCallout(FName CompanionID, FName MonsterID, bool bHasFramePerk)
{
	if (bHasFramePerk)
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenTacticalPerkCompanionAIDirectorComponent: %s triggered EARNED KNOWLEDGE callout for %s (1.0s advance)!"),
			*CompanionID.ToString(), *MonsterID.ToString());
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("UAshenTacticalPerkCompanionAIDirectorComponent: %s standard callout for %s."),
			*CompanionID.ToString(), *MonsterID.ToString());
	}
}
