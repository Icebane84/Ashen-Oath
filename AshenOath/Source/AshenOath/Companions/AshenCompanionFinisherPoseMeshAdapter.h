// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenTripartiteResonanceTypes.h"
#include "AshenCompanionFinisherPoseMeshAdapter.generated.h"

/**
 * UAshenCompanionFinisherPoseMeshAdapter
 * 
 * Modulates companion blendspace alignment and weapon readiness during Tripartite finishers.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionFinisherPoseMeshAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCompanionFinisherPoseMeshAdapter();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/** Sets target finisher readiness weight */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Companions|Trio")
	void SetFinisherPoseWeight(float TargetWeight);

	UFUNCTION(BlueprintPure, Category = "Ashen|Companions|Trio")
	float GetCurrentPoseWeight() const { return CurrentWeight; }

private:
	float CurrentWeight = 0.0f;
	float DesiredWeight = 0.0f;
};
