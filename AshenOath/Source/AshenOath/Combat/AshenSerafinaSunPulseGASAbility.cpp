// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenSerafinaSunPulseGASAbility.h"

UAshenSerafinaSunPulseGASAbility::UAshenSerafinaSunPulseGASAbility()
{
	DisorientDurationSeconds = 3.0f;
}

bool UAshenSerafinaSunPulseGASAbility::CastSunPulseFlash(AActor* CasterActor, AActor* TargetUnchainedActor)
{
	if (!CasterActor || !TargetUnchainedActor) return false;
	UE_LOG(LogTemp, Warning, TEXT("UAshenSerafinaSunPulseGASAbility: CAST SUN-PULSE! %s disoriented for %.1fs!"),
		*TargetUnchainedActor->GetName(), DisorientDurationSeconds);
	return true;
}
