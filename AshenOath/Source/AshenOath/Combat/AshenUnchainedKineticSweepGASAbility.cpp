// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenUnchainedKineticSweepGASAbility.h"

UAshenUnchainedKineticSweepGASAbility::UAshenUnchainedKineticSweepGASAbility()
{
	SweepDamage = 1100.0f;
	SweepArcDegrees = 180.0f;
}

bool UAshenUnchainedKineticSweepGASAbility::ExecuteIndiscriminateSweep(AActor* UnchainedKaelenActor)
{
	if (!UnchainedKaelenActor) return false;
	UE_LOG(LogTemp, Warning, TEXT("UAshenUnchainedKineticSweepGASAbility: UNCHAINED SWEEP on %s (%.1f DMG, %.1f deg arc)!"),
		*UnchainedKaelenActor->GetName(), SweepDamage, SweepArcDegrees);
	return true;
}
