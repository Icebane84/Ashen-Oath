// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Orchestration/AshenMacroSystemicContractTypes.h"
#include "AshenMacroSystemicMasterSpineBridge.generated.h"

/**
 * UAshenMacroSystemicMasterSpineBridge
 * 
 * Master Orchestrator binding the 9-stage closed loop:
 * - Dispatches all lifecycle delegates
 * - Arbitrates active trigger resistance priority (DialogueWillStruggle > CombatStagger > AmbientSomatic)
 * - Guarantees unbroken causal lineage tracking
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMacroSystemicMasterSpineBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenMacroSystemicMasterSpineBridge();

	/** Resolves active trigger resistance output based on priority arbitration */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Spine")
	float ArbitrateTriggerResistance(
		ETriggerResistanceSource ActiveSource,
		float DialogueResistance,
		float CombatBaselineResistance,
		float AmbientIntentResistance,
		bool bCombatPoiseBroken);

	/** Broadcasts a new trauma imprint event */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Spine")
	void BroadcastTraumaImprintCreated(const FMemoryImprintPayload& Payload);

	/** Broadcasts a trial of will resolution event */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Spine")
	void BroadcastTrialOfWillResolved(
		EWillContext Context,
		EWillTrialResult Result,
		float CompletionRatio,
		FGuid SourceTransactionId);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Spine")
	FOnTraumaImprintCreated OnTraumaImprintCreated;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Spine")
	FOnTrialOfWillResolved OnTrialOfWillResolved;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Spine")
	FOnTripartiteSyncExecuted OnTripartiteSyncExecuted;
};
