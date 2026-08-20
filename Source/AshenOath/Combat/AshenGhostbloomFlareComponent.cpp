// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenGhostbloomFlareComponent.h"

UAshenGhostbloomFlareComponent::UAshenGhostbloomFlareComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	StunDurationSeconds = 4.0f;
	FlashRadiusUnits = 600.0f;
}
void UAshenGhostbloomFlareComponent::BeginPlay() { Super::BeginPlay(); }

bool UAshenGhostbloomFlareComponent::DetonateFlashFlare(FVector DetonationLocation)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenGhostbloomFlareComponent: GHOSTBLOOM FLASH FLARE DETONATED at %s! (Radius: %.1fuu, Stun: %.1fs)!"),
		*DetonationLocation.ToString(), FlashRadiusUnits, StunDurationSeconds);
	return true;
}
