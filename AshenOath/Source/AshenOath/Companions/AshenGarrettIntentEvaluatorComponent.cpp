// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Companions/AshenGarrettIntentEvaluatorComponent.h"

UAshenGarrettIntentEvaluatorComponent::UAshenGarrettIntentEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FCompanionIntentEvaluationResult UAshenGarrettIntentEvaluatorComponent::EvaluateGarrettIntent(
	const FPlayerIntentTelemetrySnapshot& Telemetry,
	EIntentConfidenceTier ConfidenceTier) const
{
	FCompanionIntentEvaluationResult Result;
	Result.CompanionId = FName(TEXT("Garrett"));
	Result.ConfidenceTier = ConfidenceTier;

	// Case 1: Blind Wrath / Dysregulation Crisis
	if (Telemetry.SoulState.AccumulatedDysregulation >= 0.75f && Telemetry.SoulState.DominantLens == EOntologicalLens::Wrath)
	{
		Result.InferredIntent = EPlayerFormationBreakIntent::BlindWrathAssault;
		Result.SelectedResponse = ECompanionTacticalResponse::ConfrontationalIntervene;
		Result.ContextualBarkTag = FGameplayTag::RequestGameplayTag(FName(TEXT("Bark.Garrett.Confrontation.Wrath")), false);
		Result.ContextualBarkDialogue = TEXT("No. Not this time. Pull back before you get us all killed!");
		return Result;
	}

	// Case 2: Innocent Rescue / Civilian in Danger
	if (Telemetry.bTargetIsInnocent)
	{
		Result.InferredIntent = EPlayerFormationBreakIntent::InnocentRescue;

		// High Trust & High Confidence -> Commit Shoulder-to-Shoulder
		if (ConfidenceTier >= EIntentConfidenceTier::Confident)
		{
			Result.SelectedResponse = ECompanionTacticalResponse::ShoulderToShoulderCommit;
			Result.ContextualBarkTag = FGameplayTag::RequestGameplayTag(FName(TEXT("Bark.Garrett.Commit.MrHero")), false);
			Result.ContextualBarkDialogue = TEXT("Damn it. There goes our Mr. Hero again. Cover my blind spot!");
		}
		else // Low Trust -> Flank & Compensate
		{
			Result.SelectedResponse = ECompanionTacticalResponse::CautiousFlankCompensate;
			Result.ContextualBarkTag = FGameplayTag::RequestGameplayTag(FName(TEXT("Bark.Garrett.Caution.HoldPosition")), false);
			Result.ContextualBarkDialogue = TEXT("God damn it, Kaelen! I said wait! I'm taking the flank!");
		}
		return Result;
	}

	// Case 3: Tactical Flank Exploit
	Result.InferredIntent = EPlayerFormationBreakIntent::TacticalFlankExploit;
	Result.SelectedResponse = ECompanionTacticalResponse::SynchronizedPincerStrike;
	Result.ContextualBarkTag = FGameplayTag::RequestGameplayTag(FName(TEXT("Bark.Garrett.Pincer.Commit")), false);
	Result.ContextualBarkDialogue = TEXT("Got your left. Drive them toward the pillars!");
	return Result;
}
