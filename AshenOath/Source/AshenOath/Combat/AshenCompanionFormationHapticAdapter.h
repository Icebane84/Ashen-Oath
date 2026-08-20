// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCompanionFormationHapticAdapter.generated.h"

/**
 * UAshenCompanionFormationHapticAdapter
 * 
 * Drives DualSense sub-bass haptic feedback when a companion matches Kaelen's stride.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionFormationHapticAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCompanionFormationHapticAdapter();

	/** Dispatches synchronized footstep haptics */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Combat|Haptics")
	void TriggerFormationFootstepHaptic(float StrideCadence = 1.0f);

	UFUNCTION(BlueprintPure, Category = "Ashen|Combat|Haptics")
	float GetLastStrideCadence() const { return LastStride; }

private:
	float LastStride = 1.0f;
};
