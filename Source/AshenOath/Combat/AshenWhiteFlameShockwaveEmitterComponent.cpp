// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 689: Ashen White Flame Shockwave Emitter Component

#include "AshenWhiteFlameShockwaveEmitterComponent.h"

UAshenWhiteFlameShockwaveEmitterComponent::UAshenWhiteFlameShockwaveEmitterComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	TotalShockwavesEmitted = 0;
}

void UAshenWhiteFlameShockwaveEmitterComponent::EmitWhiteFlameShockwave(FVector Location, float Power)
{
	TotalShockwavesEmitted++;
	OnShockwaveEmitted.Broadcast(Location, Power);

	UE_LOG(LogTemp, Warning, TEXT("UAshenWhiteFlameShockwaveEmitterComponent: WHITE FLAME SHOCKWAVE EMITTED -> Location: (%s) | Impulse Power: %.0f (Total: %d)."),
		*Location.ToString(), Power, TotalShockwavesEmitted);
}
