// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenDiscordantHumStruggleGASAbility.h"

UAshenDiscordantHumStruggleGASAbility::UAshenDiscordantHumStruggleGASAbility()
{
	CorruptionActivationThreshold = 0.40f;
}

bool UAshenDiscordantHumStruggleGASAbility::ActivateDiscordantHumStruggle(AActor* KaelenActor)
{
	if (!KaelenActor) return false;
	UE_LOG(LogTemp, Warning, TEXT("UAshenDiscordantHumStruggleGASAbility: DISCORDANT HUM STRUGGLE ACTIVATED on %s! Dual Trigger 50%% Lock Engaged!"),
		*KaelenActor->GetName());
	return true;
}
