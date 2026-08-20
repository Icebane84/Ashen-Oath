// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenApplyBurningSteelOilGASAbility.h"

UAshenApplyBurningSteelOilGASAbility::UAshenApplyBurningSteelOilGASAbility()
{
	OilDurationSeconds = 15.0f;
}

bool UAshenApplyBurningSteelOilGASAbility::ApplyOilToWeapons(AActor* GarrettActor)
{
	if (!GarrettActor) return false;
	UE_LOG(LogTemp, Warning, TEXT("UAshenApplyBurningSteelOilGASAbility: BURNING STEEL OIL APPLIED by %s (Duration: %.1fs)!"),
		*GarrettActor->GetName(), OilDurationSeconds);
	return true;
}
