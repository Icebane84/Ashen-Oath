// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 831: Ashen Slate Grey Silhouette Post Process Volume

#include "AshenSlateGreySilhouettePostProcessVolume.h"

AAshenSlateGreySilhouettePostProcessVolume::AAshenSlateGreySilhouettePostProcessVolume()
{
	bUnbound = true;
	bIsSilhouettesActive = false;
}

void AAshenSlateGreySilhouettePostProcessVolume::TriggerSlateGreySilhouettes(bool bEnableSilhouettes)
{
	bIsSilhouettesActive = bEnableSilhouettes;
	const float Desat = bIsSilhouettesActive ? 0.90f : 0.0f;

	OnPostProcessTriggered.Broadcast(Desat, bIsSilhouettesActive);

	UE_LOG(LogTemp, Warning, TEXT("AAshenSlateGreySilhouettePostProcessVolume: SLATE-GREY SILHOUETTE POST-PROCESS TRIGGERED -> Active: %s | Desaturation: %.0f%%."),
		bIsSilhouettesActive ? TEXT("TRUE") : TEXT("FALSE"), Desat * 100.0f);
}
