// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 809: Ashen Shadow Mark Rune Etch Visual Locus Actor

#include "AshenShadowMarkRuneEtchVisualLocusActor.h"

AAshenShadowMarkRuneEtchVisualLocusActor::AAshenShadowMarkRuneEtchVisualLocusActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsRunesEtched = false;
}

void AAshenShadowMarkRuneEtchVisualLocusActor::EtchShadowMarkRunes(float GlowIntensity)
{
	bIsRunesEtched = true;
	OnShadowMarkEtched.Broadcast(GetActorLocation(), GlowIntensity);

	UE_LOG(LogTemp, Warning, TEXT("AAshenShadowMarkRuneEtchVisualLocusActor: SHADOW MARK RUNES ETCHED IN-WORLD -> Location: (%s) | Glow Intensity: %.2fx."),
		*GetActorLocation().ToString(), GlowIntensity);
}
