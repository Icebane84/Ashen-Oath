// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenUnchainedBerserkGASAbility.h"

UAshenUnchainedBerserkGASAbility::UAshenUnchainedBerserkGASAbility() {}

bool UAshenUnchainedBerserkGASAbility::ActivateUnchainedBerserk()
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenUnchainedBerserkGASAbility: UNCHAINED BERSERK ACTIVATED! Attack Multiplier: %.2fx | Hyper-Armor Poise: %.2fx"),
		AttackMultiplier, PoiseHyperArmorMultiplier);
	return true;
}
