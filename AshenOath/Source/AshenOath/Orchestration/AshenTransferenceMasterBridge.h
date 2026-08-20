// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Companions/AshenTransferenceBurnoutTypes.h"
#include "AshenTransferenceMasterBridge.generated.h"

/**
 * UAshenTransferenceMasterBridge
 * 
 * Master orchestrator connecting transference events, burnout states,
 * and moral evaluation delegates across downstream subsystems.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTransferenceMasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenTransferenceMasterBridge();

	/** Broadcasts transference absorption */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Transference")
	void BroadcastTransferenceAbsorbed(const FTransferenceBurdenSnapshot& Snapshot);

	/** Broadcasts stagger resolution */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Transference")
	void BroadcastStaggerResolution(const FMercyExecutionEvaluationResult& Result);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Transference")
	FOnTransferenceAbsorbed OnTransferenceAbsorbed;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Transference")
	FOnStaggerResolutionEvaluated OnStaggerResolutionEvaluated;
};
