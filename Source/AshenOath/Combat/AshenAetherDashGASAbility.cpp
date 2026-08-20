// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenAetherDashGASAbility.h"

UAshenAetherDashGASAbility::UAshenAetherDashGASAbility()
{
	DashDistance = 800.0f;
	DashDuration = 0.25f;
	StaminaCost = 25.0f;
}

bool UAshenAetherDashGASAbility::PerformAetherDash(AActor* InstigatorActor, const FVector& InputDirection)
{
	if (!InstigatorActor) return false;
	UE_LOG(LogTemp, Warning, TEXT("UAshenAetherDashGASAbility: Performed Aether Dash (Dist: %.1fuu, Dur: %.2fs, Cost: %.1f Stamina)."),
		DashDistance, DashDuration, StaminaCost);
	return true;
}
