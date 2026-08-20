// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenFinisherCinematicPostProcessAdapter.h"

UAshenFinisherCinematicPostProcessAdapter::UAshenFinisherCinematicPostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenFinisherCinematicPostProcessAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenFinisherCinematicPostProcessAdapter::ApplyFinisherCinematicFX(float Intensity, bool bLetterboxActive)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenFinisherCinematicPostProcessAdapter: Postprocess updated — FX Intensity: %.2f | Letterbox: %s"),
		Intensity, bLetterboxActive ? TEXT("ON") : TEXT("OFF"));
}
