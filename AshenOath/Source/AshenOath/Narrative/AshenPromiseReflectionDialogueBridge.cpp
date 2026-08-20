// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenPromiseReflectionDialogueBridge.h"

UAshenPromiseReflectionDialogueBridge::UAshenPromiseReflectionDialogueBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FText UAshenPromiseReflectionDialogueBridge::FormatPromiseDialogue(
	const FString& BasePrompt,
	const FCanonicalPromiseRecord& PromiseRecord) const
{
	if (PromiseRecord.Status == EPromiseResolutionStatus::Fulfilled)
	{
		const FString Formatted = FString::Printf(
			TEXT("%s\n[Context: You honored your sacred vow to %s: \"%s\"]"),
			*BasePrompt,
			*PromiseRecord.TargetCompanionName.ToString(),
			*PromiseRecord.PromiseText);
		return FText::FromString(Formatted);
	}

	if (PromiseRecord.Status == EPromiseResolutionStatus::Betrayed)
	{
		const FString Formatted = FString::Printf(
			TEXT("%s\n[Context: You broke your promise to %s: \"%s\"]"),
			*BasePrompt,
			*PromiseRecord.TargetCompanionName.ToString(),
			*PromiseRecord.PromiseText);
		return FText::FromString(Formatted);
	}

	const FString Formatted = FString::Printf(
		TEXT("%s\n[Context: Active vow bound to %s: \"%s\"]"),
		*BasePrompt,
		*PromiseRecord.TargetCompanionName.ToString(),
		*PromiseRecord.PromiseText);
	return FText::FromString(Formatted);
}
