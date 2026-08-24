// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Audio/AshenQuartzAudioTypes.h"
#include "AshenQuartzMasterBridge.generated.h"

/**
 * UAshenQuartzMasterBridge
 * 
 * Master orchestrator connecting Quartz music quantization, GAS abilities, UMG visualizers, dialogue downbeats, and haptics.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenQuartzMasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenQuartzMasterBridge();

	/** Broadcasts Quartz state vector */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Quartz")
	void BroadcastQuartzMatrix(const FQuartzStemMatrixState& NewState);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Quartz")
	FOnStemMatrixUpdated OnStemMatrixBroadcaster;
};
