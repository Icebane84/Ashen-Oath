// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenLivingJournalToneModulatorAdapter.h"

UAshenLivingJournalToneModulatorAdapter::UAshenLivingJournalToneModulatorAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	CurrentInkStainScalar = 0.0f;
}

void UAshenLivingJournalToneModulatorAdapter::ApplyJournalTone(const FGameplayTag& ToneTag)
{
	ActiveToneTag = ToneTag;
	if (ToneTag.ToString().Contains(TEXT("SelfAccusatory")))
	{
		CurrentInkStainScalar = 0.85f;
	}
	else
	{
		CurrentInkStainScalar = 0.20f;
	}
}
