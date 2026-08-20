// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Companions/AshenSerafinaEmpathicIntentEvaluatorComponent.h"

UAshenSerafinaEmpathicIntentEvaluatorComponent::UAshenSerafinaEmpathicIntentEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FCompanionIntentEvaluationResult UAshenSerafinaEmpathicIntentEvaluatorComponent::EvaluateSerafinaIntent(
	const FPlayerIntentTelemetrySnapshot& Telemetry,
	EIntentConfidenceTier ConfidenceTier) const
{
	FCompanionIntentEvaluationResult Result;
	Result.CompanionId = FName(TEXT("Serafina"));
	Result.ConfidenceTier = ConfidenceTier;

	if (Telemetry.bTargetIsInnocent)
	{
		Result.InferredIntent = EPlayerFormationBreakIntent::InnocentRescue;
		Result.SelectedResponse = ECompanionTacticalResponse::DefensiveSanctuaryHold;
		Result.ContextualBarkTag = FGameplayTag::RequestGameplayTag(FName(TEXT("Bark.Serafina.Sanctuary.Extend")), false);
		Result.ContextualBarkDialogue = TEXT("The flame will shelter them, Kaelen! I am behind you!");
		return Result;
	}

	Result.InferredIntent = EPlayerFormationBreakIntent::TacticalFlankExploit;
	Result.SelectedResponse = ECompanionTacticalResponse::SynchronizedPincerStrike;
	Result.ContextualBarkTag = FGameplayTag::RequestGameplayTag(FName(TEXT("Bark.Serafina.Resonance.Sync")), false);
	Result.ContextualBarkDialogue = TEXT("Let the light bind our steps.");
	return Result;
}
