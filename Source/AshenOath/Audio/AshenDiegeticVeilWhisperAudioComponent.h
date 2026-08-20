// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticVeilWhisperAudioComponent.generated.h"

/**
 * UAshenDiegeticVeilWhisperAudioComponent
 * Audio component emitting eerie veil whisper frequency modulations based on dimensional phase shift intensity.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticVeilWhisperAudioComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDiegeticVeilWhisperAudioComponent();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Audio")
	float VeilWhisperVolume = 0.5f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void UpdateVeilWhisperFrequency(float PhaseShiftIntensity);
};
