// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 716: Ashen Serafina Sacred Barrier Component

#include "AshenSerafinaSacredBarrierComponent.h"

UAshenSerafinaSacredBarrierComponent::UAshenSerafinaSacredBarrierComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	bIsBarrierActive = false;
}

void UAshenSerafinaSacredBarrierComponent::DeploySacredBarrier(FVector Location, float BarrierHealth)
{
	bIsBarrierActive = true;
	OnSacredBarrierDeployed.Broadcast(Location, BarrierHealth);

	UE_LOG(LogTemp, Warning, TEXT("UAshenSerafinaSacredBarrierComponent: SACRED BARRIER DEPLOYED -> Location: (%s) | Max Absorption: %.0f HP."),
		*Location.ToString(), BarrierHealth);
}
