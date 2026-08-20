// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Companions/AshenStaggerResolutionEvaluatorComponent.h"

UAshenStaggerResolutionEvaluatorComponent::UAshenStaggerResolutionEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FMercyExecutionEvaluationResult UAshenStaggerResolutionEvaluatorComponent::EvaluateChoice(
	EFoeStaggerResolutionChoice ChoiceMade,
	bool bTargetIsHumanoid,
	float TargetThreatLevel) const
{
	FMercyExecutionEvaluationResult Result;
	Result.ChoiceMade = ChoiceMade;

	if (ChoiceMade == EFoeStaggerResolutionChoice::MercifulBinding)
	{
		Result.SerafinaMoralPurityDelta = 0.15f;
		Result.GarrettPragmaticApprovalDelta = bTargetIsHumanoid ? 0.05f : -0.10f; // Garrett wary if monster left alive
		Result.EvaluationTag = FGameplayTag::RequestGameplayTag(FName(TEXT("Moral.Mercy.Binding")), false);
		Result.ContextualDialogue = TEXT("The flame cleanses without consuming. Thank you, Kaelen.");
		return Result;
	}

	if (ChoiceMade == EFoeStaggerResolutionChoice::RuthlessExecution)
	{
		Result.GarrettPragmaticApprovalDelta = TargetThreatLevel > 0.6f ? 0.15f : -0.05f; // Pragmatic if high threat
		Result.SerafinaMoralPurityDelta = -0.20f;
		Result.EvaluationTag = FGameplayTag::RequestGameplayTag(FName(TEXT("Moral.Execution.Ruthless")), false);
		Result.ContextualDialogue = TEXT("Dead men don't stab you in the back. Good finish.");
		return Result;
	}

	Result.EvaluationTag = FGameplayTag::RequestGameplayTag(FName(TEXT("Moral.Ignored.Disengage")), false);
	Result.ContextualDialogue = TEXT("Let us move. We have lingered too long.");
	return Result;
}
