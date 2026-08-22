// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenUserWidget_WeepingMireHUD.h"

UAshenUserWidget_WeepingMireHUD::UAshenUserWidget_WeepingMireHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	DisplayedPhase = EUnchainedVesselPhase::Dormant;
	DisplayedHeartBPM = 80.0f;
	DisplayedFrenzyRemaining = 0.0f;
	DisplayedGasDetonations = 0;
}

void UAshenUserWidget_WeepingMireHUD::UpdateSkirmishHUD(
	EUnchainedVesselPhase Phase,
	float HeartBPM,
	float FrenzyRemaining,
	int32 GasPocketsDetonated)
{
	DisplayedPhase = Phase;
	DisplayedHeartBPM = HeartBPM;
	DisplayedFrenzyRemaining = FrenzyRemaining;
	DisplayedGasDetonations = GasPocketsDetonated;
}
