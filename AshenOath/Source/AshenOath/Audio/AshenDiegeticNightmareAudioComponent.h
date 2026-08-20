// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticNightmareAudioComponent.generated.h"

/**
 * UAshenDiegeticNightmareAudioComponent
 * Manages 3D reverse-reverb whispers, sub-bass 28Hz reality distortion drones, and reality cracking sound cues.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticNightmareAudioComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDiegeticNightmareAudioComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void UpdateIncursionAudio(float IncursionIntensity, float SubBassVolume);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlayRealityCrackCue();
};
