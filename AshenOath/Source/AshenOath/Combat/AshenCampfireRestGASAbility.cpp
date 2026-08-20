// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenCampfireRestGASAbility.h"

UAshenCampfireRestGASAbility::UAshenCampfireRestGASAbility() {}

bool UAshenCampfireRestGASAbility::ActivateCampfireRestRegeneration()
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenCampfireRestGASAbility: Campfire rest regeneration active (+%.1f HP/s)!"), HealthRestorationRate);
	return true;
}
