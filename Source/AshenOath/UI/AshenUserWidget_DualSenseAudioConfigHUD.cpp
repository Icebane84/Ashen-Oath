// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_DualSenseAudioConfigHUD.h"

void UAshenUserWidget_DualSenseAudioConfigHUD::SaveAudioConfiguration(float Volume, bool bHeadphoneMix)
{
	ConfiguredSpeakerVolume = FMath::Clamp(Volume, 0.0f, 1.0f);
	bConfiguredHeadphoneDownmix = bHeadphoneMix;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_DualSenseAudioConfigHUD: Saved Config -> Speaker Volume: %.2f | Headphone Downmix: %s"),
		ConfiguredSpeakerVolume, bConfiguredHeadphoneDownmix ? TEXT("ENABLED") : TEXT("DISABLED"));
}
