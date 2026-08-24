// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenUserWidget_Scenario6FrostbiteHUD.h"

UAshenUserWidget_Scenario6FrostbiteHUD::UAshenUserWidget_Scenario6FrostbiteHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	DisplayedFrostbite = 0.0f;
	DisplayedSeverity = EFrostbiteSeverity::Normal;
	DisplayedTemperature = -15.0f;
	DisplayedHearthIgnition = 0.0f;
	bDisplayedInWarmth = false;
}

void UAshenUserWidget_Scenario6FrostbiteHUD::UpdateScenario6HUD(
	float FrostbiteGauge,
	EFrostbiteSeverity Severity,
	float TemperatureCelsius,
	float HearthIgnition,
	bool bInWarmth)
{
	DisplayedFrostbite = FrostbiteGauge;
	DisplayedSeverity = Severity;
	DisplayedTemperature = TemperatureCelsius;
	DisplayedHearthIgnition = HearthIgnition;
	bDisplayedInWarmth = bInWarmth;
}
