// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Orchestration/AshenTripartiteMasterBridge.h"

UAshenTripartiteMasterBridge::UAshenTripartiteMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenTripartiteMasterBridge::BroadcastTripartiteSync(ETripartiteBehaviorMode Mode, float AttunementScore)
{
	const float Multiplier = 1.0f + (FMath::Clamp(AttunementScore, 0.0f, 1.0f) * 2.0f);
	OnAttunementBroadcaster.Broadcast(AttunementScore, Multiplier);
}
