// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenBossChasmFractureGASAbility.h"

UAshenBossChasmFractureGASAbility::UAshenBossChasmFractureGASAbility()
{
	FissureLengthUnits = 1000.0f;
}

bool UAshenBossChasmFractureGASAbility::FractureArenaFloor(FVector OriginLocation, FVector Direction)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenBossChasmFractureGASAbility: ARENA FLOOR FRACTURED! (Span: %.1fuu at %s)!"),
		FissureLengthUnits, *OriginLocation.ToString());
	return true;
}
