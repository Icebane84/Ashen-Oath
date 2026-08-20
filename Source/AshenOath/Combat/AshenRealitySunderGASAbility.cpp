// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenRealitySunderGASAbility.h"

UAshenRealitySunderGASAbility::UAshenRealitySunderGASAbility()
{
	SunderBaseDamage = 650.0f;
	IntegrationDebtCost = 0.15f;
	CleaveRadius = 750.0f;
}

bool UAshenRealitySunderGASAbility::UnleashRealitySunder(AActor* InstigatorActor)
{
	if (!InstigatorActor) return false;
	UE_LOG(LogTemp, Warning, TEXT("UAshenRealitySunderGASAbility: Unleashed Reality Sunder Cleave (DMG: %.1f, Radius: %.1fuu, Debt Cost: +%.2f)!"),
		SunderBaseDamage, CleaveRadius, IntegrationDebtCost);
	return true;
}
