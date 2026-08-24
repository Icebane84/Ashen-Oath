// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenJournalAudioSubsystem.h"

UAshenJournalAudioSubsystem::UAshenJournalAudioSubsystem()
{
}

float UAshenJournalAudioSubsystem::EvaluateQuillScribingGain(float WritingSpeed01) const
{
	return FMath::Clamp(WritingSpeed01 * 0.75f, 0.0f, 0.75f);
}

float UAshenJournalAudioSubsystem::EvaluateCampfireCrackleGain(ECampfireReflectionMood Mood) const
{
	switch (Mood)
	{
	case ECampfireReflectionMood::SomberSilence:
		return 0.20f; // Soft distant embers
	case ECampfireReflectionMood::SharedCatharsis:
		return 0.85f; // Bright crackling fire
	case ECampfireReflectionMood::TemperedResolve:
	default:
		return 0.50f;
	}
}
