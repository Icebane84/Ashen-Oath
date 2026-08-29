// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenSeveranceTypes.h"
#include "AshenSeveranceMasterBridge.generated.h"

/**
 * UAshenSeveranceMasterBridge
 * 
 * Master orchestrator connecting combat execution triggers, dynamic mesh slicing, adrenaline state, audio, and HUD.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSeveranceMasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSeveranceMasterBridge();

	/** Broadcasts live severance execution across game modules */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Severance")
	void BroadcastSeveranceExecution(const FSeveranceDismembermentResult& Result);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Severance")
	FOnSeveranceExecuted OnSeveranceBroadcaster;
};
