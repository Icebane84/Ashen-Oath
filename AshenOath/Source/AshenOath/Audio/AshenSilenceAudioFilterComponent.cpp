// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenSilenceAudioFilterComponent.h"
#include "Components/AudioComponent.h"

UAshenSilenceAudioFilterComponent::UAshenSilenceAudioFilterComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CurrentLowPassCutoff = 20000.0f;
}

void UAshenSilenceAudioFilterComponent::ApplySilenceAcoustics(ESomaticSilenceClassification Classification)
{
	switch (Classification)
	{
	case ESomaticSilenceClassification::Contemplative:
		CurrentLowPassCutoff = 8000.0f;
		break;
	case ESomaticSilenceClassification::TraumaticAftermath:
		CurrentLowPassCutoff = 3500.0f; // Deep muffling with heartbeat prominence
		break;
	case ESomaticSilenceClassification::DestabilizingCrisis:
		CurrentLowPassCutoff = 1500.0f; // Severe underwater ringing & parasite whispers
		break;
	default:
		CurrentLowPassCutoff = 20000.0f;
		break;
	}

	if (SilenceAudioComponent)
	{
		SilenceAudioComponent->SetLowPassFilterEnabled(true);
		SilenceAudioComponent->SetLowPassFilterFrequency(CurrentLowPassCutoff);
	}
}
