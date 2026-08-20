// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenCanonicalPromiseTypes.h"
#include "AshenPromiseVowAudioEmitterComponent.generated.h"

class UAudioComponent;

/**
 * UAshenPromiseVowAudioEmitterComponent
 * 
 * Emits sacred chimes and sub-bass harmonic resonance when vows are activated.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenPromiseVowAudioEmitterComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenPromiseVowAudioEmitterComponent();

	/** Plays vow activation audio cue */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Audio|Vow")
	void PlayVowResonanceCue(EPromiseResolutionStatus Status);

	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|Vow")
	float GetVolumeMultiplier() const { return CurrentVolume; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UAudioComponent* VowAudioComponent;

private:
	float CurrentVolume = 1.0f;
};
