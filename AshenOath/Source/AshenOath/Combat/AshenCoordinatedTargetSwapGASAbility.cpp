// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenCoordinatedTargetSwapGASAbility.h"

UAshenCoordinatedTargetSwapGASAbility::UAshenCoordinatedTargetSwapGASAbility()
{
	BonusJointDamage = 850.0f;
}

bool UAshenCoordinatedTargetSwapGASAbility::ExecuteTargetSwap(AActor* KaelenActor, AActor* GarrettActor)
{
	if (!KaelenActor || !GarrettActor) return false;
	UE_LOG(LogTemp, Warning, TEXT("UAshenCoordinatedTargetSwapGASAbility: TARGET SWAP EXECUTED! Kaelen cleaves Shade | Garrett exploits Bastion joints (+%.1f DMG)!"),
		BonusJointDamage);
	return true;
}
