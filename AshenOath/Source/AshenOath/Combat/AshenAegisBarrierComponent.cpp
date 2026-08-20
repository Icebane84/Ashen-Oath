// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 582: Ashen Aegis Barrier Component

#include "AshenAegisBarrierComponent.h"

UAshenAegisBarrierComponent::UAshenAegisBarrierComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	bIsBarrierActive = false;
	ActiveBarrierStrength = 0.0f;
}

void UAshenAegisBarrierComponent::DeployAegisBarrier(float Strength)
{
	bIsBarrierActive = true;
	ActiveBarrierStrength = Strength;
	const float Absorp = 85.0f; // 85% damage absorption

	OnBarrierDeployed.Broadcast(ActiveBarrierStrength, Absorp);

	UE_LOG(LogTemp, Warning, TEXT("UAshenAegisBarrierComponent: AEGIS BARRIER DEPLOYED -> Strength: %.0f HP | Absorption: %.0f%%."),
		ActiveBarrierStrength, Absorp);
}
