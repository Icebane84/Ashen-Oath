// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenHeartstoneWillpowerResurgenceAbility.h"

UAshenHeartstoneWillpowerResurgenceAbility::UAshenHeartstoneWillpowerResurgenceAbility()
{
}

bool UAshenHeartstoneWillpowerResurgenceAbility::TriggerSanctuaryResurgence()
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenHeartstoneWillpowerResurgenceAbility: Triggered Heartstone Sanctuary Willpower Resurgence (Heal Amount: %f)."), SanctuaryResurgenceHealAmount);
	return true;
}
