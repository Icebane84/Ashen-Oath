// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenShroudKnightGASAbility.h"

UAshenShroudKnightGASAbility::UAshenShroudKnightGASAbility() {}

bool UAshenShroudKnightGASAbility::TriggerShroudParanoiaBurst(AActor* TargetActor)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenShroudKnightGASAbility: Paranoia burst triggered on %s (+%.2f Paranoia)!"),
		TargetActor ? *TargetActor->GetName() : TEXT("Target"), ParanoiaBurstAmount);
	return true;
}
