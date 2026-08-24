// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenUserWidget_Scenario9CitadelHUD.h"

UAshenUserWidget_Scenario9CitadelHUD::UAshenUserWidget_Scenario9CitadelHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	DisplayedGravityScale = 0.35f;
	DisplayedWindSpeedMps = 15.0f;
	DisplayedWindDirection = FVector(1.0f, 0.0f, 0.0f);
	DisplayedBridgeStability = 1.0f;
	DisplayedGravityTier = EVoidGravityZoneTier::LowVoidGravity;
	DisplayedWindState = EWindShearGustState::CalmBreeze;
}

void UAshenUserWidget_Scenario9CitadelHUD::UpdateCitadelHUD(
	float GravityScale,
	float WindSpeedMps,
	const FVector& WindDirection,
	float BridgeStability01,
	EVoidGravityZoneTier GravityTier,
	EWindShearGustState WindState)
{
	DisplayedGravityScale = GravityScale;
	DisplayedWindSpeedMps = WindSpeedMps;
	DisplayedWindDirection = WindDirection;
	DisplayedBridgeStability = BridgeStability01;
	DisplayedGravityTier = GravityTier;
	DisplayedWindState = WindState;
}
