// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenCompanionIntentDialogueBridge.h"

UAshenCompanionIntentDialogueBridge::UAshenCompanionIntentDialogueBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FText UAshenCompanionIntentDialogueBridge::FormatIntentDialoguePrompt(
	const FString& BasePrompt,
	FName CompanionName,
	ECompanionTacticalResponse Response) const
{
	if (Response == ECompanionTacticalResponse::ShoulderToShoulderCommit)
	{
		const FString Formatted = FString::Printf(TEXT("%s\n[Context: %s committed shoulder-to-shoulder with you]"), *BasePrompt, *CompanionName.ToString());
		return FText::FromString(Formatted);
	}
	if (Response == ECompanionTacticalResponse::ConfrontationalIntervene)
	{
		const FString Formatted = FString::Printf(TEXT("%s\n[Context: %s physically stopped your rage]"), *BasePrompt, *CompanionName.ToString());
		return FText::FromString(Formatted);
	}

	return FText::FromString(BasePrompt);
}
