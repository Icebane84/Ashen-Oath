// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 779: Ashen Oathbringer Weapon Rack World Actor

#include "AshenOathbringerWeaponRackWorldActor.h"

AAshenOathbringerWeaponRackWorldActor::AAshenOathbringerWeaponRackWorldActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsWeaponMounted = true;
}

void AAshenOathbringerWeaponRackWorldActor::InteractWithWeaponRack(AActor* InteractingPlayer)
{
	bIsWeaponMounted = !bIsWeaponMounted;
	OnRackInteracted.Broadcast(InteractingPlayer, bIsWeaponMounted);

	UE_LOG(LogTemp, Warning, TEXT("AAshenOathbringerWeaponRackWorldActor: WEAPON RACK INTERACTED -> Player: '%s' | Weapon Mounted: %s."),
		InteractingPlayer ? *InteractingPlayer->GetName() : TEXT("None"), bIsWeaponMounted ? TEXT("TRUE") : TEXT("FALSE"));
}
