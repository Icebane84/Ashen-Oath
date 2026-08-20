// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenPurificationNovaAbility.h"

UAshenPurificationNovaAbility::UAshenPurificationNovaAbility()
{
}

bool UAshenPurificationNovaAbility::TriggerPurificationNovaPulse()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenPurificationNovaAbility: Triggered radiant purification nova pulse (Radius: %f)."), PurificationNovaRadius);
	return true;
}
