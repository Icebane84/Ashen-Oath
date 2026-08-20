// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenUnchainedVoidShatterGASAbility.h"

UAshenUnchainedVoidShatterGASAbility::UAshenUnchainedVoidShatterGASAbility() {}

bool UAshenUnchainedVoidShatterGASAbility::ExecuteVoidShatter(FVector ImpactPoint)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenUnchainedVoidShatterGASAbility: VOID SHATTER executed at (%f, %f, %f)! Radius: %.0fuu | Damage: %.1f"),
		ImpactPoint.X, ImpactPoint.Y, ImpactPoint.Z, ShatterRadius, ShatterBaseDamage);
	return true;
}
