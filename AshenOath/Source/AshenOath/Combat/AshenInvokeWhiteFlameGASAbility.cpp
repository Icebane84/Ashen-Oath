// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenInvokeWhiteFlameGASAbility.h"

UAshenInvokeWhiteFlameGASAbility::UAshenInvokeWhiteFlameGASAbility()
{
	CatharsisDurationSeconds = 12.0f;
}

bool UAshenInvokeWhiteFlameGASAbility::InvokeWhiteFlame(AActor* KaelenActor, AActor* SerafinaActor)
{
	if (!KaelenActor || !SerafinaActor) return false;
	UE_LOG(LogTemp, Error, TEXT("UAshenInvokeWhiteFlameGASAbility: *** THE WHITE FLAME RESOLUTION HAS BEEN INVOKED *** (Duration: %.1fs)!"),
		CatharsisDurationSeconds);
	return true;
}
