// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenParasiticBladeTypes.h"
#include "AshenParasiticBladeMasterBridge.generated.h"

/**
 * UAshenParasiticBladeMasterBridge
 * 
 * Master orchestrator connecting Oathbringer's parasitic consciousness, blade mass physics, Garrett's Gloomwood stabilization, and audio/haptics.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenParasiticBladeMasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenParasiticBladeMasterBridge();

	/** Broadcasts blade mass update */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Blade")
	void BroadcastBladeMass(float NewMassKg);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Blade")
	FOnBladeMassRecalculated OnBladeMassBroadcaster;
};
