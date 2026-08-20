// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticWhisperAudioComponent.generated.h"

/**
 * UAshenDiegeticWhisperAudioComponent
 * Manages 3D binaural whispers, low-frequency proximity drone, and memory fragment discovery chimes.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticWhisperAudioComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDiegeticWhisperAudioComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlayWhisperDroneCue(float Intensity);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlayFragmentDiscoveryChime();
};
