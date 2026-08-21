// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenHarmonizedReflectionDialogueBridge.h"

UAshenHarmonizedReflectionDialogueBridge::UAshenHarmonizedReflectionDialogueBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FText UAshenHarmonizedReflectionDialogueBridge::FormatResonanceDialogue(
	const FString& BasePrompt,
	int32 TotalHarmonizedFinishers) const
{
	if (TotalHarmonizedFinishers > 0)
	{
		const FString Formatted = FString::Printf(
			TEXT("%s\n[Fellowship Resonance: We fought as one mind (%d Tripartite Finishers). The White Flame holds.]"),
			*BasePrompt,
			TotalHarmonizedFinishers);
		return FText::FromString(Formatted);
	}

	return FText::FromString(BasePrompt);
}
