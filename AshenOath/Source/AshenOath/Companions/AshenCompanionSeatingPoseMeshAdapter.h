// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenCampfireHearthTypes.h"
#include "AshenCompanionSeatingPoseMeshAdapter.generated.h"

/**
 * UAshenCompanionSeatingPoseMeshAdapter
 * 
 * Modulates companion blendspace sitting pose (relaxed campfire sit vs alert stance).
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionSeatingPoseMeshAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCompanionSeatingPoseMeshAdapter();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/** Sets target seating relax weight */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Companions|Hearth")
	void SetSeatingPoseWeight(float TargetWeight);

	UFUNCTION(BlueprintPure, Category = "Ashen|Companions|Hearth")
	float GetCurrentPoseWeight() const { return CurrentWeight; }

private:
	float CurrentWeight = 0.0f;
	float DesiredWeight = 0.0f;
};
