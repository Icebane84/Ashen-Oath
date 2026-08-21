// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenBossArenaTypes.h"
#include "AshenBossPhaseMeshAnimationAdapter.generated.h"

/**
 * UAshenBossPhaseMeshAnimationAdapter
 * 
 * Modulates boss blendspace animation speeds, corruption glow intensity,
 * and posture stability across Phases 1-3.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenBossPhaseMeshAnimationAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenBossPhaseMeshAnimationAdapter();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/** Sets target phase animation weight */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Boss|Animation")
	void SetPhaseCorruptionWeight(float TargetWeight);

	UFUNCTION(BlueprintPure, Category = "Ashen|Boss|Animation")
	float GetCurrentCorruptionWeight() const { return CurrentWeight; }

private:
	float CurrentWeight = 0.0f;
	float DesiredWeight = 0.0f;
};
