// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Orchestration/AshenScenario10MasterBridge.h"

UAshenScenario10MasterBridge::UAshenScenario10MasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenScenario10MasterBridge::BroadcastApotheosisUpdate(
	EApotheosisResonanceStage Stage,
	float Resonance01)
{
	OnApotheosisBroadcaster.Broadcast(Stage, Resonance01);
}
