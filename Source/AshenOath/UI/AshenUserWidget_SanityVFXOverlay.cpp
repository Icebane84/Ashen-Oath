// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 249: Ashen Sanity VFX Overlay UMG Widget

#include "AshenUserWidget_SanityVFXOverlay.h"

void UAshenUserWidget_SanityVFXOverlay::DisplaySanityVFXOverlay(float SanityPercentage, const FText& AuditoryWhisperSubtitle)
{
	DisplayedSanityPercentage = SanityPercentage;
	DisplayedWhisperSubtitle = AuditoryWhisperSubtitle;
	bOverlayActive = (SanityPercentage < 40.0f);

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_SanityVFXOverlay: Overlay updated — Sanity %.1f%%, Whisper: '%s'."),
		SanityPercentage, *AuditoryWhisperSubtitle.ToString());
}

void UAshenUserWidget_SanityVFXOverlay::HideOverlay()
{
	bOverlayActive = false;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_SanityVFXOverlay: Sanity overlay hidden."));
}
