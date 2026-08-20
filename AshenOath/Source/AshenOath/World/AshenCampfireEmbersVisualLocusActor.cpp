// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 769: Ashen Campfire Embers Visual Locus Actor

#include "AshenCampfireEmbersVisualLocusActor.h"

AAshenCampfireEmbersVisualLocusActor::AAshenCampfireEmbersVisualLocusActor()
{
	PrimaryActorTick.bCanEverTick = false;
	ActiveEmberIntensity = 1.0f;
}

void AAshenCampfireEmbersVisualLocusActor::UpdateCampfireEmberIntensity(float Intensity)
{
	ActiveEmberIntensity = FMath::Clamp(Intensity, 0.0f, 3.0f);
	const float Radius = ActiveEmberIntensity * 400.0f;

	OnEmbersUpdated.Broadcast(ActiveEmberIntensity, Radius);

	UE_LOG(LogTemp, Warning, TEXT("AAshenCampfireEmbersVisualLocusActor: CAMPFIRE EMBERS UPDATED -> Intensity: %.2f | Warmth Radius: %.0f units."),
		ActiveEmberIntensity, Radius);
}
