// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenComboChainEvaluatorComponent.h"

UAshenComboChainEvaluatorComponent::UAshenComboChainEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CurrentState.CurrentPhase = ETripartiteComboPhase::Inactive;
}

FTripartiteComboState UAshenComboChainEvaluatorComponent::StartCombo(float WindowSeconds)
{
	CurrentState.ComboSessionId = FGuid::NewGuid().ToString(EGuidFormats::DigitsWithHyphensLower);
	CurrentState.CurrentPhase = ETripartiteComboPhase::Step1_KaelenCleave;
	CurrentState.RemainingWindowSeconds = WindowSeconds;
	CurrentState.bGarrettInProximity = false;
	CurrentState.bSerafinaInProximity = false;
	CurrentState.FinisherTier = EHarmonizedFinisherTier::StandardTripartite;

	return CurrentState;
}

FTripartiteComboState UAshenComboChainEvaluatorComponent::ProgressToStep2(bool bGarrettNear)
{
	if (CurrentState.CurrentPhase == ETripartiteComboPhase::Step1_KaelenCleave && bGarrettNear)
	{
		CurrentState.CurrentPhase = ETripartiteComboPhase::Step2_GarrettSnare;
		CurrentState.bGarrettInProximity = true;
	}
	return CurrentState;
}

FTripartiteComboState UAshenComboChainEvaluatorComponent::ProgressToStep3(bool bSerafinaNear)
{
	if (CurrentState.CurrentPhase == ETripartiteComboPhase::Step2_GarrettSnare && bSerafinaNear)
	{
		CurrentState.CurrentPhase = ETripartiteComboPhase::FinisherReady;
		CurrentState.bSerafinaInProximity = true;
		CurrentState.FinisherTier = EHarmonizedFinisherTier::RadiantCatharsis;
	}
	return CurrentState;
}

void UAshenComboChainEvaluatorComponent::ResetCombo()
{
	CurrentState.CurrentPhase = ETripartiteComboPhase::Inactive;
	CurrentState.RemainingWindowSeconds = 0.0f;
	CurrentState.bGarrettInProximity = false;
	CurrentState.bSerafinaInProximity = false;
}
