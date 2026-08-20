// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenConsequenceProfileEvaluatorComponent.h"

UAshenConsequenceProfileEvaluatorComponent::UAshenConsequenceProfileEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenConsequenceProfileEvaluatorComponent::BeginPlay() { Super::BeginPlay(); }

EConsequenceProfileTier UAshenConsequenceProfileEvaluatorComponent::EvaluateEncounterTier(bool bIsBossEncounter, bool bIsEliteSymbiote, bool bIsSyncFinisher)
{
	if (bIsBossEncounter && bIsSyncFinisher)
	{
		return EConsequenceProfileTier::Milestone; // Tier III Full Convergence
	}
	else if (bIsEliteSymbiote || (bIsBossEncounter && !bIsSyncFinisher))
	{
		return EConsequenceProfileTier::Rare; // Tier II
	}
	return EConsequenceProfileTier::Common; // Tier I
}
