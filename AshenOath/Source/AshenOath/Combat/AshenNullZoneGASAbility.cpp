// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenNullZoneGASAbility.h"

UAshenNullZoneGASAbility::UAshenNullZoneGASAbility()
{
	PurgeRadius = 800.0f;
	BasePurgeDamage = 450.0f;
}

bool UAshenNullZoneGASAbility::UnleashPurgeShockwave(AActor* InstigatorActor, float CurrentIntegrationDebt)
{
	if (!InstigatorActor) return false;
	const float EffectiveDamage = BasePurgeDamage * (1.0f + CurrentIntegrationDebt);
	UE_LOG(LogTemp, Warning, TEXT("UAshenNullZoneGASAbility: Unleashed Purge Shockwave! (Radius: %.1f, Damage: %.1f from Debt: %.2f)"),
		PurgeRadius, EffectiveDamage, CurrentIntegrationDebt);
	return true;
}
