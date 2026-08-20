// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenSerafinaGroundingVoiceGASAbility.h"

UAshenSerafinaGroundingVoiceGASAbility::UAshenSerafinaGroundingVoiceGASAbility()
{
	CorruptionReductionPercent = 0.20f;
}

bool UAshenSerafinaGroundingVoiceGASAbility::TriggerGroundingVoice(AActor* InstigatorActor, AActor* TargetKaelen)
{
	if (!InstigatorActor || !TargetKaelen) return false;
	UE_LOG(LogTemp, Warning, TEXT("UAshenSerafinaGroundingVoiceGASAbility: Serafina DualSense Grounding: \"Kaelen. Come back.\" (Purged -%.0f%% Corruption)!"),
		CorruptionReductionPercent * 100.0f);
	return true;
}
