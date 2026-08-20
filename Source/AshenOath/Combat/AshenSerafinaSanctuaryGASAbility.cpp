// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenSerafinaSanctuaryGASAbility.h"

UAshenSerafinaSanctuaryGASAbility::UAshenSerafinaSanctuaryGASAbility() {}

bool UAshenSerafinaSanctuaryGASAbility::CastSanctuaryRing(FVector CastLocation)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenSerafinaSanctuaryGASAbility: Consecrated sanctuary ring casted at (%f, %f, %f)!"),
		CastLocation.X, CastLocation.Y, CastLocation.Z);
	return true;
}
