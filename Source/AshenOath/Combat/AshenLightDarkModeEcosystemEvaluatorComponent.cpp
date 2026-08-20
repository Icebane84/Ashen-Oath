// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenLightDarkModeEcosystemEvaluatorComponent.h"

UAshenLightDarkModeEcosystemEvaluatorComponent::UAshenLightDarkModeEcosystemEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenLightDarkModeEcosystemEvaluatorComponent::BeginPlay() { Super::BeginPlay(); }

EEcosystemModeReaction UAshenLightDarkModeEcosystemEvaluatorComponent::EvaluateCreatureReaction(FName CreatureID, bool bIsKaelenInDarkMode) const
{
	if (CreatureID == FName(TEXT("Creature.Glimmerdrake")))
	{
		return bIsKaelenInDarkMode ? EEcosystemModeReaction::ShadowedPanic : EEcosystemModeReaction::TranquilityBuff;
	}
	else if (CreatureID == FName(TEXT("Creature.SorrowLeech")))
	{
		return bIsKaelenInDarkMode ? EEcosystemModeReaction::DespairParasite : EEcosystemModeReaction::FlameAttraction;
	}

	return bIsKaelenInDarkMode ? EEcosystemModeReaction::ShadowedPanic : EEcosystemModeReaction::TranquilityBuff;
}
