// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Orchestration/AshenCompanionIntentMasterBridge.h"

UAshenCompanionIntentMasterBridge::UAshenCompanionIntentMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenCompanionIntentMasterBridge::BroadcastCompanionIntent(const FCompanionIntentEvaluationResult& Result)
{
	OnCompanionIntentEvaluated.Broadcast(Result);
}

void UAshenCompanionIntentMasterBridge::BroadcastShoulderToShoulder(FName CompanionName, float PoiseScalar)
{
	OnShoulderToShoulderInitiated.Broadcast(CompanionName, PoiseScalar);
}
