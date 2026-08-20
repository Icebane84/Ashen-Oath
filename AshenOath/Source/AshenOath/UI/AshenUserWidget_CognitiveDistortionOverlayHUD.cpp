// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenUserWidget_CognitiveDistortionOverlayHUD.h"

UAshenUserWidget_CognitiveDistortionOverlayHUD::UAshenUserWidget_CognitiveDistortionOverlayHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	CurrentIntensity = 0.0f;
}

void UAshenUserWidget_CognitiveDistortionOverlayHUD::SetDistortionParameters(
	const FGameplayTag& DistortionType,
	float Intensity)
{
	ActiveDistortionTag = DistortionType;
	CurrentIntensity = FMath::Clamp(Intensity, 0.0f, 1.0f);
}
