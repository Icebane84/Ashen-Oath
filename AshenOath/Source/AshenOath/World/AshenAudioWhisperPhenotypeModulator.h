// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenAudioWhisperPhenotypeModulator.generated.h"

/**
 * UAshenAudioWhisperPhenotypeModulator
 *
 * Maps IntegrationDebt & Corruption to diegetic whisper audio density and spatialization.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenAudioWhisperPhenotypeModulator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenAudioWhisperPhenotypeModulator();

	/** Updates audio whisper volume and density multiplier */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Audio")
	void UpdateWhisperDensity(float IntegrationDebt, float Corruption);

	/** Returns whisper volume multiplier */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Audio")
	float GetWhisperVolumeMultiplier() const { return WhisperVolumeMultiplier; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|Audio")
	float WhisperVolumeMultiplier = 0.0f;
};
