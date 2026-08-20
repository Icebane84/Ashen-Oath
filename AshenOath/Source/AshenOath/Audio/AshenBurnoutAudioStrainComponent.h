// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Companions/AshenTransferenceBurnoutTypes.h"
#include "AshenBurnoutAudioStrainComponent.generated.h"

class UAudioComponent;

/**
 * UAshenBurnoutAudioStrainComponent
 * 
 * Modulates audio pitch, breath cadence, and vocal filters based on companion burnout tier.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenBurnoutAudioStrainComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenBurnoutAudioStrainComponent();

	/** Updates audio strain based on burnout severity */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Audio|Burnout")
	void UpdateBurnoutAudioFilter(EBurnoutSeverityTier Tier);

	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|Burnout")
	float GetCurrentPitchModulation() const { return CurrentPitch; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UAudioComponent* StrainAudioComponent;

private:
	float CurrentPitch = 1.0f;
};
