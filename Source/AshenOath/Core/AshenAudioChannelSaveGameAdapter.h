// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenAudioChannelSaveGameAdapter.generated.h"

/**
 * UAshenAudioChannelSaveGameAdapter
 * Serializes player DualSense speaker preferences, volume calibration, and accessibility downmix configurations.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenAudioChannelSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenAudioChannelSaveGameAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Core")
	bool SaveAudioChannelSettings(bool bSpeakerEnabled, float SpeakerVol, bool bHeadphoneMix);
};
