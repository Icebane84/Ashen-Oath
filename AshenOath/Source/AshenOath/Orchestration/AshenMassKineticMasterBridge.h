// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenMassKineticTypes.h"
#include "AshenMassKineticMasterBridge.generated.h"

/**
 * UAshenMassKineticMasterBridge
 * 
 * Master orchestrator connecting kinetic cleaves, structural destructions,
 * and audio/visual feedback channels.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMassKineticMasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenMassKineticMasterBridge();

	/** Broadcasts kinetic swing calculation */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Kinetic")
	void BroadcastKineticSwing(const FKineticSwingSnapshot& Snapshot);

	/** Broadcasts volume drag update */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Kinetic")
	void BroadcastVolumeDrag(const FVolumeDragResult& Result);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Kinetic")
	FOnKineticSwingCalculated OnKineticSwingCalculated;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Kinetic")
	FOnVolumeDragUpdated OnVolumeDragUpdated;
};
