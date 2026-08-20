// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenCrimsonStaticPostProcessAdapter.h"

UAshenCrimsonStaticPostProcessAdapter::UAshenCrimsonStaticPostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	CrimsonStaticIntensity = 0.0f;
}
void UAshenCrimsonStaticPostProcessAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenCrimsonStaticPostProcessAdapter::TriggerCrimsonStaticFlash(float Intensity)
{
	CrimsonStaticIntensity = FMath::Clamp(Intensity, 0.0f, 1.0f);
	UE_LOG(LogTemp, Warning, TEXT("UAshenCrimsonStaticPostProcessAdapter: Crimson Static Border Bleed Intensity: %.2f"),
		CrimsonStaticIntensity);
}
