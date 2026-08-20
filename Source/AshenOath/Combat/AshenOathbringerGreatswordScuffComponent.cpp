// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 776: Ashen Oathbringer Greatsword Scuff Component

#include "AshenOathbringerGreatswordScuffComponent.h"

UAshenOathbringerGreatswordScuffComponent::UAshenOathbringerGreatswordScuffComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	ActiveScuffWearPercent = 0.0f;
}

void UAshenOathbringerGreatswordScuffComponent::ApplyCombatScuffWear(float WearDelta)
{
	ActiveScuffWearPercent = FMath::Clamp(ActiveScuffWearPercent + WearDelta, 0.0f, 100.0f);
	const float Roughness = 0.2f + (ActiveScuffWearPercent * 0.006f); // Roughness increases as metal is scratched

	OnScuffUpdated.Broadcast(ActiveScuffWearPercent, Roughness);

	UE_LOG(LogTemp, Warning, TEXT("UAshenOathbringerGreatswordScuffComponent: OATHBRINGER WEAR UPDATED -> Surface Wear: %.1f%% | Metallic Roughness: %.3f."),
		ActiveScuffWearPercent, Roughness);
}
