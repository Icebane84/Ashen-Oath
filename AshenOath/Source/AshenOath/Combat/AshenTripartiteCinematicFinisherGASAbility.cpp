// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenTripartiteCinematicFinisherGASAbility.h"

UAshenTripartiteCinematicFinisherGASAbility::UAshenTripartiteCinematicFinisherGASAbility()
{
	FinisherDamage = 2500.0f;
}

bool UAshenTripartiteCinematicFinisherGASAbility::ExecuteTripartiteFinisher(AActor* BossActor)
{
	if (!BossActor) return false;
	UE_LOG(LogTemp, Error, TEXT("UAshenTripartiteCinematicFinisherGASAbility: *** TRIPARTITE CINEMATIC FINISHER STRUCK %s (%.1f DMG) ***!"),
		*BossActor->GetName(), FinisherDamage);
	return true;
}
