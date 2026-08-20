// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenWeaveAegisNetGASAbility.h"

UAshenWeaveAegisNetGASAbility::UAshenWeaveAegisNetGASAbility()
{
	AegisDurationSeconds = 6.0f;
	TotalShieldLayers = 2;
}

bool UAshenWeaveAegisNetGASAbility::DeployAegisNetOnTarget(AActor* TargetCharacter)
{
	if (!TargetCharacter) return false;
	UE_LOG(LogTemp, Warning, TEXT("UAshenWeaveAegisNetGASAbility: LUMINOUS AEGIS NET DEPLOYED on %s (Duration: %.1fs, Shields: %d)!"),
		*TargetCharacter->GetName(), AegisDurationSeconds, TotalShieldLayers);
	return true;
}
