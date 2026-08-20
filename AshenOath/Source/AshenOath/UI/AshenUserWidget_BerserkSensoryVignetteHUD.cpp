// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenUserWidget_BerserkSensoryVignetteHUD.h"

UAshenUserWidget_BerserkSensoryVignetteHUD::UAshenUserWidget_BerserkSensoryVignetteHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	CurrentIntensity = 0.0f;
}

void UAshenUserWidget_BerserkSensoryVignetteHUD::SetVignetteIntensity(float TargetIntensity)
{
	CurrentIntensity = FMath::Clamp(TargetIntensity, 0.0f, 1.0f);
}
