// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Companions/AshenTransferenceBurnoutTypes.h"
#include "AshenCompanionFatigueMeshAdapter.generated.h"

/**
 * UAshenCompanionFatigueMeshAdapter
 * 
 * Modulates companion skeletal mesh shoulder slump and recovery blend weights
 * during heavy somatic fatigue.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionFatigueMeshAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCompanionFatigueMeshAdapter();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/** Sets target fatigue level */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Companions|Fatigue")
	void SetTargetFatigueWeight(float TargetWeight);

	UFUNCTION(BlueprintPure, Category = "Ashen|Companions|Fatigue")
	float GetCurrentFatigueWeight() const { return CurrentFatigue; }

private:
	float CurrentFatigue = 0.0f;
	float DesiredFatigue = 0.0f;
};
