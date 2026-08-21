// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenCampfireAudioFilterComponent.h"

UAshenCampfireAudioFilterComponent::UAshenCampfireAudioFilterComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenCampfireAudioFilterComponent::EvaluateAcousticWarmth(ECampfireRestTier RestTier) const
{
	switch (RestTier)
	{
	case ECampfireRestTier::MinorRest:
		return 1.15f;
	case ECampfireRestTier::ReflectiveTransmute:
		return 1.35f;
	case ECampfireRestTier::SolemnVigil:
		return 1.60f; // Maximum intimacy and crackling acoustic presence
	default:
		return 1.00f;
	}
}
