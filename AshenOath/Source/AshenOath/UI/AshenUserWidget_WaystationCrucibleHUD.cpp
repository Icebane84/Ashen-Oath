// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenUserWidget_WaystationCrucibleHUD.h"

UAshenUserWidget_WaystationCrucibleHUD::UAshenUserWidget_WaystationCrucibleHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	DisplayedRunMode = EWaystationRunMode::RunA_ShadowHarvest;
	DisplayedSerafinaDistance = 1000.0f;
	DisplayedHesitationMS = 300.0f;
	DisplayedDebt = 0.20f;
}

void UAshenUserWidget_WaystationCrucibleHUD::UpdateCrucibleHUD(
	EWaystationRunMode Mode,
	float SerafinaDistance,
	float HesitationLatencyMS,
	float IntegrationDebt)
{
	DisplayedRunMode = Mode;
	DisplayedSerafinaDistance = SerafinaDistance;
	DisplayedHesitationMS = HesitationLatencyMS;
	DisplayedDebt = IntegrationDebt;
}
