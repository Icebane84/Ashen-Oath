// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenNPCFearReactivityAnimAdapter.h"

UAshenNPCFearReactivityAnimAdapter::UAshenNPCFearReactivityAnimAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenNPCFearReactivityAnimAdapter::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	NPCFearPostureWeight = FMath::Clamp(NewState.Corruption * 1.0f, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenNPCFearReactivityAnimAdapter: Civilian NPC fear posture weight updated to %.2f"), NPCFearPostureWeight);
}
