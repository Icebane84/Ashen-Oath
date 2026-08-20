// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenSerafinaTransferenceGASAbility.h"

UAshenSerafinaTransferenceGASAbility::UAshenSerafinaTransferenceGASAbility() {}

bool UAshenSerafinaTransferenceGASAbility::ActivateTransferenceAbility(AActor* TargetAlly, float HealingPower)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenSerafinaTransferenceGASAbility: Transference channeled onto target ally (Healing: %.1f)!"), HealingPower);
	return true;
}
