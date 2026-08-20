// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Companions/AshenSomaticSilenceTypes.h"
#include "AshenSilenceAudioFilterComponent.generated.h"

class UAudioComponent;

/**
 * UAshenSilenceAudioFilterComponent
 * 
 * Modulates audio acoustics during silence:
 * - Contemplative: Atmospheric muffling, soft wind reverb
 * - Traumatic: Sub-bass heartbeat, ringing high-frequency filter
 * - Destabilizing: Creeping parasite whisper overlay
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSilenceAudioFilterComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSilenceAudioFilterComponent();

	/** Applies acoustic filter based on silence classification */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Audio|Silence")
	void ApplySilenceAcoustics(ESomaticSilenceClassification Classification);

	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|Silence")
	float GetLowPassFrequencyCutoff() const { return CurrentLowPassCutoff; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UAudioComponent* SilenceAudioComponent;

private:
	float CurrentLowPassCutoff = 20000.0f;
};
