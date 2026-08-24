// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenUserWidget_Scenario8AbyssHUD.h"

UAshenUserWidget_Scenario8AbyssHUD::UAshenUserWidget_Scenario8AbyssHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	DisplayedTorchFuel = 1.0f;
	DisplayedLightRadiusUU = 800.0f;
	DisplayedAccuracyPenalty = 0.0f;
	DisplayedSonarRadiusUU = 0.0f;
	DisplayedLightState = ELightEnvironmentState::RadiantIlluminated;
}

void UAshenUserWidget_Scenario8AbyssHUD::UpdateAbyssHUD(
	float TorchFuel01,
	float LightRadiusUU,
	float AccuracyPenalty01,
	float SonarRadiusUU,
	ELightEnvironmentState LightState)
{
	DisplayedTorchFuel = TorchFuel01;
	DisplayedLightRadiusUU = LightRadiusUU;
	DisplayedAccuracyPenalty = AccuracyPenalty01;
	DisplayedSonarRadiusUU = SonarRadiusUU;
	DisplayedLightState = LightState;
}
