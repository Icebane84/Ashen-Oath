// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenMindscapeShatterNovaAbility.h"

UAshenMindscapeShatterNovaAbility::UAshenMindscapeShatterNovaAbility()
{
}

bool UAshenMindscapeShatterNovaAbility::TriggerShatterNovaExecution()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenMindscapeShatterNovaAbility: Triggered psychic mindscape shatter nova execution (Damage: %f)."), ShatterNovaDamage);
	return true;
}
