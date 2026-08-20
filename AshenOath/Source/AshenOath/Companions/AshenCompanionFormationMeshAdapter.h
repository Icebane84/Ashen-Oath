// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Companions/AshenCompanionIntentTypes.h"
#include "AshenCompanionFormationMeshAdapter.generated.h"

/**
 * UAshenCompanionFormationMeshAdapter
 * 
 * Modulates companion skeletal mesh lean and stride parameters during formation charges.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionFormationMeshAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCompanionFormationMeshAdapter();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/** Sets active formation charge state */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Companions|Mesh")
	void SetFormationChargeActive(bool bInCharge, float LeanAngle);

	UFUNCTION(BlueprintPure, Category = "Ashen|Companions|Mesh")
	float GetCurrentLeanAngle() const { return CurrentLean; }

private:
	float CurrentLean = 0.0f;
	float TargetLean = 0.0f;
};
