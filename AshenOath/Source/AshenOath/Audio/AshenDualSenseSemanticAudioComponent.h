// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Orchestration/AshenMacroSystemicContractTypes.h"
#include "AshenDualSenseSemanticAudioComponent.generated.h"

class USoundBase;
class UAudioComponent;

/**
 * UAshenDualSenseSemanticAudioComponent
 * 
 * Hardware-agnostic semantic audio router:
 * - On PS5 DualSense: Routes parasitic intrusive whispers directly to the controller speaker.
 * - On PC/Xbox/Standard: Applies 400Hz Low-Pass Filter world audio ducking with center-head spatial panning.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDualSenseSemanticAudioComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDualSenseSemanticAudioComponent();

	virtual void BeginPlay() override;

	/** Plays a parasitic voice whisper through the hardware-appropriate audio path */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Audio|Semantic")
	void PlayParasiteWhisper(USoundBase* WhisperSound, float Intensity);

	/** Updates audio ducking and low-pass filter cutoff based on ParasitePressure */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Audio|Semantic")
	void UpdateAcousticFiltering(float ParasitePressure);

	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|Semantic")
	bool IsDualSenseSpeakerAvailable() const { return bDualSenseSpeakerAvailable; }

	UFUNCTION(BlueprintCallable, Category = "Ashen|Audio|Semantic")
	void SetDualSenseSpeakerAvailable(bool bAvailable) { bDualSenseSpeakerAvailable = bAvailable; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Audio|Semantic")
	float BaseWorldLowPassCutoffHz = 20000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Audio|Semantic")
	float MaxParasiteDuckingCutoffHz = 400.0f;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UAudioComponent* WhisperingAudioComponent;

private:
	bool bDualSenseSpeakerAvailable = true;
	float CurrentLowPassCutoff = 20000.0f;
};
