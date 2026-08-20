// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Orchestration/AshenSomaticSilenceMasterBridge.h"

UAshenSomaticSilenceMasterBridge::UAshenSomaticSilenceMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSomaticSilenceMasterBridge::BroadcastSilenceClassified(const FSilenceEvaluationSnapshot& Snapshot)
{
	OnSilenceClassified.Broadcast(Snapshot);
}

void UAshenSomaticSilenceMasterBridge::BroadcastWordlessSupport(const FWordlessSupportCommand& Command)
{
	OnWordlessSupportDispatched.Broadcast(Command);
}
