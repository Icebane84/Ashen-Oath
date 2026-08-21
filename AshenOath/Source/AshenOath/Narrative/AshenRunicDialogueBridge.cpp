// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenRunicDialogueBridge.h"

UAshenRunicDialogueBridge::UAshenRunicDialogueBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FText UAshenRunicDialogueBridge::FormatRunicAttunementDialogue(
	const FString& BasePrompt,
	const FName& RuneId,
	float EffectiveMassKg) const
{
	const FString Formatted = FString::Printf(
		TEXT("%s\n[Runic Forge: Socketed '%s'. Weapon Mass calibrated to %.1f kg.]"),
		*BasePrompt,
		*RuneId.ToString(),
		EffectiveMassKg);
	return FText::FromString(Formatted);
}
