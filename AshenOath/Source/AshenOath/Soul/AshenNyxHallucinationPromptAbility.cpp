// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 748: Ashen Nyx Hallucination Prompt Ability

#include "AshenNyxHallucinationPromptAbility.h"

void UAshenNyxHallucinationPromptAbility::TriggerHallucinationPrompt(FText PromptText, float EntropyImpact)
{
	OnPromptExecuted.Broadcast(PromptText, EntropyImpact);

	UE_LOG(LogTemp, Warning, TEXT("UAshenNyxHallucinationPromptAbility: HALLUCINATION PROMPT TRIGGERED -> Prompt: '%s' | Entropy Impact: +%.1f."),
		*PromptText.ToString(), EntropyImpact);
}
