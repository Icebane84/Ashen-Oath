// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenWhiteFlameSurgeGASAbility.h"

UAshenWhiteFlameSurgeGASAbility::UAshenWhiteFlameSurgeGASAbility()
{
}

bool UAshenWhiteFlameSurgeGASAbility::TriggerWhiteFlameSurgeStrike()
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenWhiteFlameSurgeGASAbility: Triggered White Flame Surge counter-attack (Damage: %f)."), WhiteFlameSurgeDamage);
	return true;
}
