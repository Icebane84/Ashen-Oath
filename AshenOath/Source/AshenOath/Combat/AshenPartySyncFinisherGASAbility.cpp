// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenPartySyncFinisherGASAbility.h"

UAshenPartySyncFinisherGASAbility::UAshenPartySyncFinisherGASAbility() {}

bool UAshenPartySyncFinisherGASAbility::ExecuteFinisherAbility(EAshenPartyFinisherType FinisherType, AActor* TargetActor)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenPartySyncFinisherGASAbility: Executed Finisher Type %d on %s with %.1f damage and %.2fx slow-mo!"),
		(int32)FinisherType, TargetActor ? *TargetActor->GetName() : TEXT("Target"), FinisherDamage, FinisherSlowMoDilation);
	return true;
}
