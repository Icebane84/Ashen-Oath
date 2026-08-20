// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenInnerVoiceCompilerTypes.h"
#include "Orchestration/AshenMacroSystemicContractTypes.h"
#include "AshenInnerVoiceMasterOrchestratorBridge.generated.h"

/**
 * UAshenInnerVoiceMasterOrchestratorBridge
 * 
 * Master lifecycle dispatcher connecting the Inner Voice Compiler subsystem
 * to combat abilities, UI widgets, and audio actuators.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenInnerVoiceMasterOrchestratorBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenInnerVoiceMasterOrchestratorBridge();

	/** Broadcasts inner voice compiled event */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Voice")
	void BroadcastVoiceCompilationCompleted(const FAshenInnerVoicePayload& ValidatedPayload);

	/** Broadcasts firewall error event */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Voice")
	void BroadcastFirewallError(const FString& CompilationId, EFirewallValidationResult ErrorReason);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Voice")
	FOnInnerVoiceCompilationCompleted OnInnerVoiceCompilationCompleted;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Voice")
	FOnFirewallValidationFailed OnFirewallValidationFailed;
};
