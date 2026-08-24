// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenCampfireWarmthPostProcessAdapter.h"

UAshenCampfireWarmthPostProcessAdapter::UAshenCampfireWarmthPostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenCampfireWarmthPostProcessAdapter::EvaluateHearthWarmthIntensity(ECampfireReflectionMood Mood) const
{
	switch (Mood)
	{
	case ECampfireReflectionMood::SomberSilence:
		return 0.30f;
	case ECampfireReflectionMood::SharedCatharsis:
		return 0.90f;
	case ECampfireReflectionMood::TemperedResolve:
	default:
		return 0.65f;
	}
}

float UAshenCampfireWarmthPostProcessAdapter::EvaluateParchmentSepiaVignette(bool bJournalOpen) const
{
	return bJournalOpen ? 0.75f : 0.0f;
}
