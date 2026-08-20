// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenKineticDestructionDialogueBridge.h"

UAshenKineticDestructionDialogueBridge::UAshenKineticDestructionDialogueBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FText UAshenKineticDestructionDialogueBridge::FormatDestructionDialogue(
	const FString& BasePrompt,
	FName CompanionName,
	int32 ShatteredStructuresCount) const
{
	if (ShatteredStructuresCount > 5)
	{
		const FString Formatted = FString::Printf(
			TEXT("%s\n[%s: \"The way you swung that blade... you weren't just fighting enemies, Kaelen. You were tearing the earth apart. Don't lose yourself to that weight.\"]"),
			*BasePrompt,
			*CompanionName.ToString());
		return FText::FromString(Formatted);
	}

	return FText::FromString(BasePrompt);
}
