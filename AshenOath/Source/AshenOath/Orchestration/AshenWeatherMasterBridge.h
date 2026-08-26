// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenDynamicWeatherTypes.h"
#include "AshenWeatherMasterBridge.generated.h"

/**
 * UAshenWeatherMasterBridge
 * 
 * Master orchestrator connecting the dynamic weather subsystem, GAS atmospheric abilities, UMG weather widgets, and audio synthesizers.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenWeatherMasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenWeatherMasterBridge();

	/** Broadcasts live atmospheric weather change */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Weather")
	void BroadcastWeatherState(EWeatherHazardState NewState, float Temperature);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Weather")
	FOnWeatherStateChanged OnWeatherBroadcaster;
};
