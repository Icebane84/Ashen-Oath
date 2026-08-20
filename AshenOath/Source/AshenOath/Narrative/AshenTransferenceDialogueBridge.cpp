// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenTransferenceDialogueBridge.h"

UAshenTransferenceDialogueBridge::UAshenTransferenceDialogueBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FText UAshenTransferenceDialogueBridge::FormatTransferenceDialoguePrompt(
	const FString& BasePrompt,
	EBurnoutSeverityTier BurnoutTier) const
{
	if (BurnoutTier == EBurnoutSeverityTier::Exhausted || BurnoutTier == EBurnoutSeverityTier::CriticalCollapse)
	{
		const FString Formatted = FString::Printf(TEXT("%s\n[Context: Serafina is physically trembling from absorbed trauma]"), *BasePrompt);
		return FText::FromString(Formatted);
	}
	if (BurnoutTier == EBurnoutSeverityTier::Strained)
	{
		const FString Formatted = FString::Printf(TEXT("%s\n[Context: Serafina's voice carries palpable strain]"), *BasePrompt);
		return FText::FromString(Formatted);
	}

	return FText::FromString(BasePrompt);
}
