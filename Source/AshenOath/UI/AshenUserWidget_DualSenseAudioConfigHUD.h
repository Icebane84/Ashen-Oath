// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_DualSenseAudioConfigHUD.generated.h"

/**
 * UAshenUserWidget_DualSenseAudioConfigHUD
 * Settings HUD allowing players to calibrate controller speaker volume, toggle headphone downmix, and configure subtitle accessibility tags.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_DualSenseAudioConfigHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float ConfiguredSpeakerVolume = 1.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	bool bConfiguredHeadphoneDownmix = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void SaveAudioConfiguration(float Volume, bool bHeadphoneMix);
};
