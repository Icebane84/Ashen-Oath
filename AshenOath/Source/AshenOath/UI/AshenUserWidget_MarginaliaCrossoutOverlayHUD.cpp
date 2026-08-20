// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenUserWidget_MarginaliaCrossoutOverlayHUD.h"

UAshenUserWidget_MarginaliaCrossoutOverlayHUD::UAshenUserWidget_MarginaliaCrossoutOverlayHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	Intensity = 1.0f;
}

void UAshenUserWidget_MarginaliaCrossoutOverlayHUD::TriggerCrossoutAnimation(
	const FString& TargetEntryId,
	float CrossoutIntensity)
{
	TargetId = TargetEntryId;
	Intensity = FMath::Clamp(CrossoutIntensity, 0.0f, 1.0f);
}
