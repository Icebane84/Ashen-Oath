// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenKineticBerserkTypes.h"
#include "AshenKineticBerserkMasterBridge.generated.h"

/**
 * UAshenKineticBerserkMasterBridge
 * 
 * Master orchestrator unifying angular ripostes, debris audio occlusion, Niagara shearing, and target lock.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenKineticBerserkMasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenKineticBerserkMasterBridge();

	/** Broadcasts completion of an angular riposte counter sequence */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|KineticBerserk")
	void BroadcastRiposteCompleted(EAshenCounterAttackZone Zone, float KineticJoules);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|KineticBerserk")
	FOnAngularCounterMapped OnRiposteSequenceFinished;
};
