// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Orchestration/AshenInnerVoiceMasterOrchestratorBridge.h"

UAshenInnerVoiceMasterOrchestratorBridge::UAshenInnerVoiceMasterOrchestratorBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenInnerVoiceMasterOrchestratorBridge::BroadcastVoiceCompilationCompleted(const FAshenInnerVoicePayload& ValidatedPayload)
{
	OnInnerVoiceCompilationCompleted.Broadcast(ValidatedPayload);
}

void UAshenInnerVoiceMasterOrchestratorBridge::BroadcastFirewallError(const FString& CompilationId, EFirewallValidationResult ErrorReason)
{
	OnFirewallValidationFailed.Broadcast(CompilationId, ErrorReason);
}
