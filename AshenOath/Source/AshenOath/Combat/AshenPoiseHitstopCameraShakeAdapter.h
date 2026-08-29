// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenCombatKinematicsTypes.h"
#include "AshenPoiseHitstopCameraShakeAdapter.generated.h"

/**
 * UAshenPoiseHitstopCameraShakeAdapter
 * 
 * Adapts camera trauma impulses and screen shake oscillations for poise break shatter events (+0.40) and heavy roll impacts (+0.25).
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenPoiseHitstopCameraShakeAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenPoiseHitstopCameraShakeAdapter();

	/** Evaluates camera trauma to apply for the given combat event */
	UFUNCTION(BlueprintPure, Category = "Ashen|Kinematics|Camera")
	float EvaluateCombatCameraTrauma(EPoiseStaggerState StaggerState, EAshenWeightClass WeightClass, bool bDidDodge) const;
};
