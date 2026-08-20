// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenTacticalWeakpointExposeGASAbility.h"

UAshenTacticalWeakpointExposeGASAbility::UAshenTacticalWeakpointExposeGASAbility()
{
	VulnerabilityDamageMultiplier = 1.30f;
}

bool UAshenTacticalWeakpointExposeGASAbility::ExposeWeakpoint(AActor* TargetActor)
{
	if (!TargetActor) return false;
	UE_LOG(LogTemp, Warning, TEXT("UAshenTacticalWeakpointExposeGASAbility: Garrett exposed weakpoint on %s (+%.0f%% DMG)!"),
		*TargetActor->GetName(), (VulnerabilityDamageMultiplier - 1.0f) * 100.0f);
	return true;
}
