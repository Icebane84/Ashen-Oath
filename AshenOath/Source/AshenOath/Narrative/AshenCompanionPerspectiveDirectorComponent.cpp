// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenCompanionPerspectiveDirectorComponent.h"

UAshenCompanionPerspectiveDirectorComponent::UAshenCompanionPerspectiveDirectorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	PerspectiveVector.Pragmatism = 0.5f;
	PerspectiveVector.Dogma = 0.5f;
	PerspectiveVector.HistoricalTruth = 0.5f;
}

void UAshenCompanionPerspectiveDirectorComponent::AdjustWeights(
	float DeltaPragmatism,
	float DeltaDogma,
	float DeltaTruth)
{
	PerspectiveVector.Pragmatism = FMath::Clamp(PerspectiveVector.Pragmatism + DeltaPragmatism, 0.0f, 1.0f);
	PerspectiveVector.Dogma = FMath::Clamp(PerspectiveVector.Dogma + DeltaDogma, 0.0f, 1.0f);
	PerspectiveVector.HistoricalTruth = FMath::Clamp(PerspectiveVector.HistoricalTruth + DeltaTruth, 0.0f, 1.0f);
}
