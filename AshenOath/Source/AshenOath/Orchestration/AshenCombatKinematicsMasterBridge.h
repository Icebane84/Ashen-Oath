// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenCombatKinematicsTypes.h"
#include "AshenCombatKinematicsMasterBridge.generated.h"

/**
 * UAshenCombatKinematicsMasterBridge
 * 
 * Master orchestrator bridging the equipment component, stamina pulse, poise component, audio mixer, and GAS ability activations.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCombatKinematicsMasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCombatKinematicsMasterBridge();

	/** Broadcasts live combat kinematics update across all listener domains */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Kinematics")
	void BroadcastKinematicsState(EAshenWeightClass WeightClass, float WeightRatio);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Kinematics")
	FOnWeightClassChanged OnKinematicsBroadcaster;
};
