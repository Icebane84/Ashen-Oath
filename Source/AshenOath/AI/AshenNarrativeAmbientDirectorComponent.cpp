// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "AI/AshenNarrativeAmbientDirectorComponent.h"

UAshenNarrativeAmbientDirectorComponent::UAshenNarrativeAmbientDirectorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	MinChatterCooldown = 30.0f;
}
void UAshenNarrativeAmbientDirectorComponent::BeginPlay() { Super::BeginPlay(); }

bool UAshenNarrativeAmbientDirectorComponent::ShouldTriggerAmbientBark(float TimeSinceLastBark, bool bInCombat) const
{
	if (bInCombat) return false;
	const bool bReady = TimeSinceLastBark >= MinChatterCooldown;

	UE_LOG(LogTemp, Log, TEXT("UAshenNarrativeAmbientDirectorComponent: Ambient bark readiness: %s (Time: %.1fs, Cooldown: %.1fs)."),
		bReady ? TEXT("READY") : TEXT("COOLDOWN"), TimeSinceLastBark, MinChatterCooldown);

	return bReady;
}
