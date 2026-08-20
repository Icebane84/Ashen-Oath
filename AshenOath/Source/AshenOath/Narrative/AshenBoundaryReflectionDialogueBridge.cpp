// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenBoundaryReflectionDialogueBridge.h"

UAshenBoundaryReflectionDialogueBridge::UAshenBoundaryReflectionDialogueBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FText UAshenBoundaryReflectionDialogueBridge::FormatBoundaryDialogue(
	const FString& BasePrompt,
	FName CompanionName,
	bool bHadRecentBoundaryRefusal) const
{
	if (bHadRecentBoundaryRefusal)
	{
		const FString Formatted = FString::Printf(
			TEXT("%s\n[Context: %s held their ground earlier, refusing to enable your self-destruction]"),
			*BasePrompt,
			*CompanionName.ToString());
		return FText::FromString(Formatted);
	}

	return FText::FromString(BasePrompt);
}
