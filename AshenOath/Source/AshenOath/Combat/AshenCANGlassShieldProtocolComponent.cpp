// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 643: Ashen CAN Glass Shield Protocol Component

#include "AshenCANGlassShieldProtocolComponent.h"

UAshenCANGlassShieldProtocolComponent::UAshenCANGlassShieldProtocolComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	ActiveGlassShieldHealth = 0.0f;
}

void UAshenCANGlassShieldProtocolComponent::DeployGlassShield(float BaseStrength)
{
	ActiveGlassShieldHealth = FMath::Clamp(BaseStrength, 0.0f, 500.0f);
	const bool bWillFracture = (ActiveGlassShieldHealth < 200.0f);

	OnGlassShieldDeployed.Broadcast(ActiveGlassShieldHealth, bWillFracture);

	UE_LOG(LogTemp, Warning, TEXT("UAshenCANGlassShieldProtocolComponent: GLASS SHIELD DEPLOYED -> Health: %.0f | Will Fracture: %s (can-glass_shield_protocol)."),
		ActiveGlassShieldHealth, bWillFracture ? TEXT("TRUE") : TEXT("FALSE"));
}
