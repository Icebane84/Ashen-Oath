// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 797: Ashen Combat Grammar Feedback Component

#include "AshenCombatGrammarFeedbackComponent.h"

UAshenCombatGrammarFeedbackComponent::UAshenCombatGrammarFeedbackComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	ActiveGrammarState = FName(TEXT("Grammar.WhiteFlame"));
}

void UAshenCombatGrammarFeedbackComponent::TriggerGrammarFeedback(FName GrammarTag, float Intensity)
{
	ActiveGrammarState = GrammarTag;
	OnGrammarTriggered.Broadcast(ActiveGrammarState, Intensity);

	UE_LOG(LogTemp, Warning, TEXT("UAshenCombatGrammarFeedbackComponent: COMBAT GRAMMAR TRIGGERED -> State: '%s' | Intensity: %.2fx."),
		*ActiveGrammarState.ToString(), Intensity);
}
