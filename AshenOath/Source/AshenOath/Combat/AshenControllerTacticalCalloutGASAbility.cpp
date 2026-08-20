// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenControllerTacticalCalloutGASAbility.h"

UAshenControllerTacticalCalloutGASAbility::UAshenControllerTacticalCalloutGASAbility()
{
	ActionWindowSeconds = 1.25f;
}

bool UAshenControllerTacticalCalloutGASAbility::TriggerTacticalCallout(AActor* InstigatorActor, FName TargetEnemyID)
{
	if (!InstigatorActor) return false;
	UE_LOG(LogTemp, Warning, TEXT("UAshenControllerTacticalCalloutGASAbility: Garrett DualSense Callout: \"Kaelen. Now.\" (Window: %.2fs) on %s!"),
		ActionWindowSeconds, *TargetEnemyID.ToString());
	return true;
}
