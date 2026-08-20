// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenTrialOfWillStaggerGASAbility.h"

UAshenTrialOfWillStaggerGASAbility::UAshenTrialOfWillStaggerGASAbility()
{
	StaggerDilationDuration = 0.75f;
}

bool UAshenTrialOfWillStaggerGASAbility::ActivateTrialOfWillCrisis(AActor* InstigatorHero)
{
	if (!InstigatorHero) return false;
	UE_LOG(LogTemp, Warning, TEXT("UAshenTrialOfWillStaggerGASAbility: Poise Broken on %s! TRIAL OF WILL ACTIVATED for %.2fs!"),
		*InstigatorHero->GetName(), StaggerDilationDuration);
	return true;
}
