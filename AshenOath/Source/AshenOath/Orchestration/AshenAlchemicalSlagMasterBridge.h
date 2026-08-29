// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenAlchemicalSlagTypes.h"
#include "AshenAlchemicalSlagMasterBridge.generated.h"

/**
 * UAshenAlchemicalSlagMasterBridge
 * 
 * Master orchestrator connecting campfire cauldron brewing, blade soot accumulation, GAS abilities, HUD indicators, and haptics.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenAlchemicalSlagMasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenAlchemicalSlagMasterBridge();

	/** Broadcasts live soot and surface state update */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|AlchemicalSlag")
	void BroadcastSootUpdate(float SootLevel, EOathbringerBladeSurfaceState SurfaceState);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|AlchemicalSlag")
	FOnBladeSootLevelChanged OnSootBroadcaster;
};
