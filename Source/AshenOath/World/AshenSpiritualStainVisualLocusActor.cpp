// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 692: Ashen Spiritual Stain Visual Locus Actor

#include "AshenSpiritualStainVisualLocusActor.h"

AAshenSpiritualStainVisualLocusActor::AAshenSpiritualStainVisualLocusActor()
{
	PrimaryActorTick.bCanEverTick = false;
	ActiveLocusStainDensity = 0.0f;
}

void AAshenSpiritualStainVisualLocusActor::UpdateStainDensity(float StainDensity)
{
	ActiveLocusStainDensity = FMath::Clamp(StainDensity, 0.0f, 1.0f);
	const bool bCorroding = (ActiveLocusStainDensity > 0.5f);

	OnStainLocusUpdated.Broadcast(ActiveLocusStainDensity, bCorroding);

	UE_LOG(LogTemp, Warning, TEXT("AAshenSpiritualStainVisualLocusActor: STAIN LOCUS DENSITY UPDATED -> Density: %.2f | Corroding Geometry: %s."),
		ActiveLocusStainDensity, bCorroding ? TEXT("TRUE") : TEXT("FALSE"));
}
