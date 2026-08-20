// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Companions/AshenSomaticSilenceTypes.h"
#include "AshenCompanionSilenceMeshAdapter.generated.h"

/**
 * UAshenCompanionSilenceMeshAdapter
 * 
 * Modulates companion head tracking gaze weight toward Kaelen during contemplative
 * and traumatic silence states.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionSilenceMeshAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCompanionSilenceMeshAdapter();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/** Sets target gaze weight toward Kaelen */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Companions|Silence")
	void SetSilenceGazeWeight(float TargetWeight);

	UFUNCTION(BlueprintPure, Category = "Ashen|Companions|Silence")
	float GetCurrentGazeWeight() const { return CurrentGazeWeight; }

private:
	float CurrentGazeWeight = 0.0f;
	float DesiredGazeWeight = 0.0f;
};
