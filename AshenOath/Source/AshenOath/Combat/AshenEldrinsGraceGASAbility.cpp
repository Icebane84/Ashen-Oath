// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenEldrinsGraceGASAbility.h"

UAshenEldrinsGraceGASAbility::UAshenEldrinsGraceGASAbility()
{
}

bool UAshenEldrinsGraceGASAbility::ActivateEldrinsGraceStance()
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenEldrinsGraceGASAbility: Activated Eldrin's Grace agility & multi-parry stance (Parry Window Multiplier: %f)."), GraceParryWindowMultiplier);
	return true;
}
