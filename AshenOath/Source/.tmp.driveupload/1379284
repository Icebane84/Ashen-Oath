// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenInnerVoiceMeshTremorAdapter.h"

UAshenInnerVoiceMeshTremorAdapter::UAshenInnerVoiceMeshTremorAdapter()
{
	PrimaryComponentTick.bCanEverTick = true;
	TremorInterpSpeed = 5.0f;
	CurrentTremor = 0.0f;
	TargetTremor = 0.0f;
}

void UAshenInnerVoiceMeshTremorAdapter::TickComponent(
	float DeltaTime,
	ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	CurrentTremor = FMath::FInterpTo(CurrentTremor, TargetTremor, DeltaTime, TremorInterpSpeed);
}

void UAshenInnerVoiceMeshTremorAdapter::UpdateTremor(
	EVoiceChannel ActiveChannel,
	float DistortionIntensity)
{
	if (ActiveChannel == EVoiceChannel::ShadowSelf)
	{
		TargetTremor = FMath::Clamp(DistortionIntensity * 0.75f, 0.0f, 1.0f);
	}
	else
	{
		TargetTremor = 0.0f;
	}
}
