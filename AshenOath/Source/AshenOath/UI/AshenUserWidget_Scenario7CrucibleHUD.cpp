// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenUserWidget_Scenario7CrucibleHUD.h"

UAshenUserWidget_Scenario7CrucibleHUD::UAshenUserWidget_Scenario7CrucibleHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	DisplayedAmbientTempC = 45.0f;
	DisplayedHeatExhaustion = 0.0f;
	DisplayedStaminaDrainMultiplier = 1.0f;
	DisplayedBladeTempC = 20.0f;
	DisplayedBladeState = ETemperedBladeState::ColdSteel;
	DisplayedSurgePhase = ECalderaSurgePhase::DormantCalm;
}

void UAshenUserWidget_Scenario7CrucibleHUD::UpdateCrucibleHUD(
	float AmbientTempC,
	float HeatExhaustion01,
	float StaminaDrainMult,
	float BladeTempC,
	ETemperedBladeState BladeState,
	ECalderaSurgePhase SurgePhase)
{
	DisplayedAmbientTempC = AmbientTempC;
	DisplayedHeatExhaustion = HeatExhaustion01;
	DisplayedStaminaDrainMultiplier = StaminaDrainMult;
	DisplayedBladeTempC = BladeTempC;
	DisplayedBladeState = BladeState;
	DisplayedSurgePhase = SurgePhase;
}
