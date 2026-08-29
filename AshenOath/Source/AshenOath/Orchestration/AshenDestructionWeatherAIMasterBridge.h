// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenDestructionWeatherAITypes.h"
#include "AshenDestructionWeatherAIMasterBridge.generated.h"

/**
 * UAshenDestructionWeatherAIMasterBridge
 * 
 * Master orchestrator connecting Chaos destruction rubble, dynamic weather perception, Lock-On component, and AI behavior trees.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDestructionWeatherAIMasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDestructionWeatherAIMasterBridge();

	/** Broadcasts live tactical atmospheric update across listener domains */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Convergence")
	void BroadcastTacticalUpdate(EAtmosphericVisibilityTier Tier, float LockOnRange);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Convergence")
	FOnWeatherPerceptionClamped OnTacticalBroadcaster;
};
