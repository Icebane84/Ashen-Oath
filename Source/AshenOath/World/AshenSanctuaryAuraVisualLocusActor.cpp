// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 732: Ashen Sanctuary Aura Visual Locus Actor

#include "AshenSanctuaryAuraVisualLocusActor.h"

AAshenSanctuaryAuraVisualLocusActor::AAshenSanctuaryAuraVisualLocusActor()
{
	PrimaryActorTick.bCanEverTick = false;
	ActiveGlyphRadius = 500.0f;
}

void AAshenSanctuaryAuraVisualLocusActor::UpdateSanctuaryGlyphRadius(float Radius)
{
	ActiveGlyphRadius = FMath::Clamp(Radius, 100.0f, 3000.0f);
	const bool bGlowing = (ActiveGlyphRadius > 300.0f);

	OnSanctuaryLocusUpdated.Broadcast(ActiveGlyphRadius, bGlowing);

	UE_LOG(LogTemp, Warning, TEXT("AAshenSanctuaryAuraVisualLocusActor: SANCTUARY GLYPH RADIUS UPDATED -> Radius: %.0f units | Glowing: %s."),
		ActiveGlyphRadius, bGlowing ? TEXT("TRUE") : TEXT("FALSE"));
}
