// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenDialogueChoiceEvaluatorComponent.h"

UAshenDialogueChoiceEvaluatorComponent::UAshenDialogueChoiceEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenDialogueChoiceEvaluatorComponent::BeginPlay() { Super::BeginPlay(); }

float UAshenDialogueChoiceEvaluatorComponent::EvaluateDialogueOptionTrustScore(FName CompanionID, float BaseTrustMultiplier) const
{
	const float FinalScore = 1.0f * BaseTrustMultiplier;
	UE_LOG(LogTemp, Log, TEXT("UAshenDialogueChoiceEvaluatorComponent: Evaluated dialogue score for %s: %.2f"), *CompanionID.ToString(), FinalScore);
	return FinalScore;
}
