// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenSovereignPhoenixAscensionAbility.h"

UAshenSovereignPhoenixAscensionAbility::UAshenSovereignPhoenixAscensionAbility()
{
}

bool UAshenSovereignPhoenixAscensionAbility::TriggerSovereignPhoenixAscension()
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenSovereignPhoenixAscensionAbility: Triggered Ascension of the White Flame! Map-wide purification active (Radius: %f)."), AscensionPurificationRadius);
	return true;
}
