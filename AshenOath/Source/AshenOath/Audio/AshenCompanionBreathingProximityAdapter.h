// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCompanionBreathingProximityAdapter.generated.h"

class UAudioComponent;

/**
 * UAshenCompanionBreathingProximityAdapter
 * 
 * Synchronizes companion heavy breathing audio with Kaelen's stride during
 * close-formation charges.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionBreathingProximityAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCompanionBreathingProximityAdapter();

	/** Updates breathing volume based on proximity */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Audio|Breathing")
	void UpdateBreathingProximity(float DistanceToKaelen, bool bIsSprinting);

	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|Breathing")
	float GetBreathingVolumeScalar() const { return CurrentVolume; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UAudioComponent* BreathingAudioComponent;

private:
	float CurrentVolume = 0.0f;
};
