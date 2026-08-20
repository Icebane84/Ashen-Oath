// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Soul/AshenInnerVoiceCompilerTypes.h"
#include "Orchestration/AshenMacroSystemicContractTypes.h"
#include "AshenInnerVoiceCompilerSubsystem.generated.h"

class UAshenCognitiveFirewallValidator;
class UAshenDeterministicVoiceFallbackProvider;

/**
 * UAshenInnerVoiceCompilerSubsystem
 * 
 * Central World Subsystem managing the Inner Voice Compiler (IVC-001):
 * - Evaluates Salience Gate triggers to avoid unneeded compilation
 * - Serializes telemetry into FAshenVoiceIngestPacket
 * - Dispatches async worker tasks and passes results through the 4-stage C++ Firewall
 * - Dispatches validated payloads to DualSense, HUD, and Living Journal
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenInnerVoiceCompilerSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenInnerVoiceCompilerSubsystem();

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	/** Requests an inner voice compilation pass if salience condition is met */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Soul|Voice")
	bool RequestVoiceCompilation(
		ESalienceTriggerClass TriggerClass,
		const FCanonicalSoulStateVector& CurrentSoulState,
		const FGameplayTag& ActiveStanceTag,
		const FString& ActiveEchoId,
		const TArray<FString>& AuthorizedImprints);

	/** Manually feeds raw JSON output for firewall validation */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Soul|Voice")
	bool ProcessCompilerOutput(
		const FAshenInnerVoicePayload& RawPayload,
		const TArray<FString>& AuthorizedImprints);

	UFUNCTION(BlueprintPure, Category = "Ashen|Soul|Voice")
	bool IsCompilationInFlight() const { return bInFlight; }

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Soul|Voice")
	FOnInnerVoiceCompilationCompleted OnInnerVoiceCompilationCompleted;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Soul|Voice")
	FOnFirewallValidationFailed OnFirewallValidationFailed;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Soul|Voice")
	FOnSalienceGateTriggered OnSalienceGateTriggered;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Soul|Voice")
	FOnMonologueAudioDispatched OnMonologueAudioDispatched;

protected:
	UPROPERTY()
	UAshenCognitiveFirewallValidator* FirewallValidator;

	UPROPERTY()
	UAshenDeterministicVoiceFallbackProvider* FallbackProvider;

private:
	bool bInFlight = false;
	FCanonicalSoulStateVector CachedSoulState;
};
