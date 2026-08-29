// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenUserWidget_CombatKinematicsHUD.h"

UAshenUserWidget_CombatKinematicsHUD::UAshenUserWidget_CombatKinematicsHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	DisplayedKinematics.CurrentEquipmentWeightKg = 25.0f;
	DisplayedKinematics.MaxEquipLoadKg = 50.0f;
	DisplayedKinematics.WeightClass = EAshenWeightClass::MediumLoad;
	DisplayedKinematics.bInCardiacExhaustion = false;
	DisplayedKinematics.SwingWindupSlowdown = 0.0f;
	DisplayedKinematics.StaggerState = EPoiseStaggerState::SolidGuard;
	DisplayedKinematics.bRiposteBuffActive = false;
}

void UAshenUserWidget_CombatKinematicsHUD::UpdateKinematicsHUD(
	const FCombatKinematicsVector& Kinematics)
{
	DisplayedKinematics = Kinematics;
}
