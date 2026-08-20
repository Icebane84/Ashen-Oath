// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenPyreCleaveGASAbility.h"

UAshenPyreCleaveGASAbility::UAshenPyreCleaveGASAbility()
{
	PyreCleaveDamage = 1800.0f;
}

bool UAshenPyreCleaveGASAbility::ExecutePyreCleave(AActor* TargetActor)
{
	if (!TargetActor) return false;
	UE_LOG(LogTemp, Warning, TEXT("UAshenPyreCleaveGASAbility: WHITE PYRE CLEAVE STRUCK %s! (%.1f Holy-Kinetic DMG)!"),
		*TargetActor->GetName(), PyreCleaveDamage);
	return true;
}
