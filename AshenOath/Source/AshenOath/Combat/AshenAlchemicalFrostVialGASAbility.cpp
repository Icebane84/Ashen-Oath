// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenAlchemicalFrostVialGASAbility.h"

UAshenAlchemicalFrostVialGASAbility::UAshenAlchemicalFrostVialGASAbility()
{
	FrostDamage = 250.0f;
	BlastRadius = 600.0f;
	SlowMultiplier = 0.40f;
	SlowDuration = 6.0f;
}

bool UAshenAlchemicalFrostVialGASAbility::ThrowFrostVial(AActor* InstigatorActor, const FVector& TargetLocation)
{
	if (!InstigatorActor) return false;
	UE_LOG(LogTemp, Warning, TEXT("UAshenAlchemicalFrostVialGASAbility: Threw Frost Vial at %s (DMG: %.1f, Radius: %.1fuu, Slow: %.2fx for %.1fs)."),
		*TargetLocation.ToString(), FrostDamage, BlastRadius, SlowMultiplier, SlowDuration);
	return true;
}
