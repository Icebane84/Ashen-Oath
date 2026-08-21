// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenUserWidget_DualSenseHapticHUD.h"

UAshenUserWidget_DualSenseHapticHUD::UAshenUserWidget_DualSenseHapticHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	DisplayedLeftResistance = 0.0f;
	DisplayedRightResistance = 0.0f;
	bIsLockoutActive = false;
}

void UAshenUserWidget_DualSenseHapticHUD::UpdateTriggerDisplay(
	const FDualSenseTriggerConfig& Left,
	const FDualSenseTriggerConfig& Right)
{
	DisplayedLeftResistance = Left.ResistanceForce;
	DisplayedRightResistance = Right.ResistanceForce;
	bIsLockoutActive = (Left.Mode == EHapticTriggerEffectMode::WeaponLockout || Right.Mode == EHapticTriggerEffectMode::WeaponLockout);
}
