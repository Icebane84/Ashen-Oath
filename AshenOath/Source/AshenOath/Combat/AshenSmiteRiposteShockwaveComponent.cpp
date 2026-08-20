// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 668: Ashen Smite Riposte Shockwave Component

#include "AshenSmiteRiposteShockwaveComponent.h"

UAshenSmiteRiposteShockwaveComponent::UAshenSmiteRiposteShockwaveComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	TotalSmiteRipostesExecuted = 0;
}

void UAshenSmiteRiposteShockwaveComponent::TriggerSmiteRiposte(float Radius, float Damage)
{
	TotalSmiteRipostesExecuted++;
	OnSmiteRiposteTriggered.Broadcast(Radius, Damage);

	UE_LOG(LogTemp, Warning, TEXT("UAshenSmiteRiposteShockwaveComponent: SMITE RIPOSTE SHOCKWAVE TRIGGERED -> Radius: %.0f units | White Flame Damage: %.0f (Total: %d)."),
		Radius, Damage, TotalSmiteRipostesExecuted);
}
