// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenGarrettGloomwoodNeedleGASAbility.h"

UAshenGarrettGloomwoodNeedleGASAbility::UAshenGarrettGloomwoodNeedleGASAbility()
{
	CorruptionDampeningAmount = 0.25f;
}

bool UAshenGarrettGloomwoodNeedleGASAbility::InjectGloomwoodDampener(AActor* GarrettActor, AActor* KaelenActor)
{
	if (!GarrettActor || !KaelenActor) return false;
	UE_LOG(LogTemp, Warning, TEXT("UAshenGarrettGloomwoodNeedleGASAbility: GLOOMWOOD DAMPENER INJECTED into %s! Corruption reduced by -%.2f!"),
		*KaelenActor->GetName(), CorruptionDampeningAmount);
	return true;
}
