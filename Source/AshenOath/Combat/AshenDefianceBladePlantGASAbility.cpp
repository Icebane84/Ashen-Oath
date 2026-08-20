// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenDefianceBladePlantGASAbility.h"

UAshenDefianceBladePlantGASAbility::UAshenDefianceBladePlantGASAbility()
{
	PoiseHardeningRatio = 0.50f;
	IntegrationDebtSpike = 2.5f;
}

bool UAshenDefianceBladePlantGASAbility::ExecuteDefiancePlant(AActor* KaelenActor)
{
	if (!KaelenActor) return false;
	UE_LOG(LogTemp, Warning, TEXT("UAshenDefianceBladePlantGASAbility: DEFIANCE EXECUTED on %s! Planted Oathbringer -> 50%% Poise Hardened (Debt +%.1f)!"),
		*KaelenActor->GetName(), IntegrationDebtSpike);
	return true;
}
