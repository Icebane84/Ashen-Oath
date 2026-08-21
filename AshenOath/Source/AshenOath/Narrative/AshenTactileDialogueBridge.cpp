// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenTactileDialogueBridge.h"

UAshenTactileDialogueBridge::UAshenTactileDialogueBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FText UAshenTactileDialogueBridge::FormatTactileDialogue(
	const FString& BasePrompt,
	ETactileWhisperChannel Channel,
	bool bLockoutEngaged) const
{
	const FString Formatted = FString::Printf(
		TEXT("%s\n[DualSense Haptic: %s | Will Lockout: %s]"),
		*BasePrompt,
		(Channel == ETactileWhisperChannel::GarrettTactical) ? TEXT("Garrett Whisper") : TEXT("Standard Audio"),
		bLockoutEngaged ? TEXT("ENGAGED (100% Resistance)") : TEXT("DISENGAGED"));
	return FText::FromString(Formatted);
}
