// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenBurnoutAudioStrainComponent.h"
#include "Components/AudioComponent.h"

UAshenBurnoutAudioStrainComponent::UAshenBurnoutAudioStrainComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CurrentPitch = 1.0f;
}

void UAshenBurnoutAudioStrainComponent::UpdateBurnoutAudioFilter(EBurnoutSeverityTier Tier)
{
	switch (Tier)
	{
	case EBurnoutSeverityTier::Nominal:
		CurrentPitch = 1.0f;
		break;
	case EBurnoutSeverityTier::Strained:
		CurrentPitch = 0.95f;
		break;
	case EBurnoutSeverityTier::Exhausted:
		CurrentPitch = 0.88f;
		break;
	case EBurnoutSeverityTier::CriticalCollapse:
		CurrentPitch = 0.80f;
		break;
	}

	if (StrainAudioComponent)
	{
		StrainAudioComponent->SetPitchMultiplier(CurrentPitch);
	}
}
