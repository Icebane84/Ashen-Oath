// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenBrotherMalakorGASAbility.h"

UAshenBrotherMalakorGASAbility::UAshenBrotherMalakorGASAbility() {}

bool UAshenBrotherMalakorGASAbility::CastRadiantScriptureStrike(AActor* TargetActor)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenBrotherMalakorGASAbility: Radiant Scripture Strike cast on %s (Damage: %.1f)!"),
		TargetActor ? *TargetActor->GetName() : TEXT("Target"), RadiantDamage);
	return true;
}
