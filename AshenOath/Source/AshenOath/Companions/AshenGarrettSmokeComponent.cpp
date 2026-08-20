// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Companions/AshenGarrettSmokeComponent.h"

UAshenGarrettSmokeComponent::UAshenGarrettSmokeComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenGarrettSmokeComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenGarrettSmokeComponent::DeploySmokeCanister(FVector DetonationLocation)
{
	if (OnSmokeCanisterDetonated.IsBound())
	{
		OnSmokeCanisterDetonated.Broadcast(DetonationLocation, SmokeRadius);
	}
	UE_LOG(LogTemp, Warning, TEXT("UAshenGarrettSmokeComponent: Smoke canister detonated at (%f, %f, %f) with radius %.0fuu"),
		DetonationLocation.X, DetonationLocation.Y, DetonationLocation.Z, SmokeRadius);
}
