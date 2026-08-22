// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Combat/AshenKineticBerserkTypes.h"
#include "AshenKineticBerserkSubsystem.generated.h"

/**
 * UAshenKineticBerserkSubsystem
 * 
 * Central world subsystem orchestrating PRS-001 kinetic combat pipelines, debris occlusion, and angular ripostes.
 */
UCLASS()
class ASHENOATH_API UAshenKineticBerserkSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenKineticBerserkSubsystem();

	/** Broadcasts angular counter mapping */
	UFUNCTION(BlueprintCallable, Category = "Ashen|KineticBerserk")
	void NotifyAngularCounterMapped(EAshenCounterAttackZone Zone, float AngleDegrees);

	/** Broadcasts debris occlusion frequency change */
	UFUNCTION(BlueprintCallable, Category = "Ashen|KineticBerserk")
	void NotifyDebrisOcclusionUpdated(float CutoffFrequency, EAshenDebrisOcclusionState State);

	/** Broadcasts planar geometry exit shear event */
	UFUNCTION(BlueprintCallable, Category = "Ashen|KineticBerserk")
	void NotifyPlanarExitShear(const FVector& ExitCoordinate, const FVector& ShearVector);

	UFUNCTION(BlueprintPure, Category = "Ashen|KineticBerserk")
	int32 GetRipostesExecutedCount() const { return TotalRipostesExecuted; }

	UPROPERTY(BlueprintAssignable, Category = "Ashen|KineticBerserk")
	FOnAngularCounterMapped OnAngularCounterMapped;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|KineticBerserk")
	FOnDebrisOcclusionUpdated OnDebrisOcclusionUpdated;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|KineticBerserk")
	FOnPlanarExitShearSpawned OnPlanarExitShearSpawned;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|KineticBerserk")
	FOnTargetTrackingLocked OnTargetTrackingLocked;

private:
	int32 TotalRipostesExecuted = 0;
};
