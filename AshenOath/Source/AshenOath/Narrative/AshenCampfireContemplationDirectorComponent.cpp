// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenCampfireContemplationDirectorComponent.h"

UAshenCampfireContemplationDirectorComponent::UAshenCampfireContemplationDirectorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CurrentMood = ECampfireReflectionMood::TemperedResolve;
}

ECampfireReflectionMood UAshenCampfireContemplationDirectorComponent::EvaluateCampfireMood(
	float TrustScore01,
	float Debt01)
{
	if (Debt01 >= 0.70f || TrustScore01 < 0.40f)
	{
		CurrentMood = ECampfireReflectionMood::SomberSilence;
	}
	else if (TrustScore01 >= 0.75f)
	{
		CurrentMood = ECampfireReflectionMood::SharedCatharsis;
	}
	else
	{
		CurrentMood = ECampfireReflectionMood::TemperedResolve;
	}

	return CurrentMood;
}

float UAshenCampfireContemplationDirectorComponent::RestAtCampfire(float RestDurationSeconds)
{
	// 5 seconds rest restores up to 25% sanity (0.05 per sec)
	const float SanityRestored = FMath::Clamp(RestDurationSeconds * 0.05f, 0.0f, 0.25f);
	return SanityRestored;
}
