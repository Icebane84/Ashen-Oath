// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenUnreliableNarratorGASAbility.h"

UAshenUnreliableNarratorGASAbility::UAshenUnreliableNarratorGASAbility() {}

bool UAshenUnreliableNarratorGASAbility::DispelHallucinatoryMirage()
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenUnreliableNarratorGASAbility: Willpower pulse dispelled active hallucinatory mirages!"));
	return true;
}
