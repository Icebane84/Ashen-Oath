// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 702: Ashen Garrett Poison Blade Execution Ability

#include "AshenGarrettPoisonBladeExecutionAbility.h"

void UAshenGarrettPoisonBladeExecutionAbility::ExecutePoisonBlade(AActor* TargetEnemy, float TargetArmorScuffLevel)
{
	if (!TargetEnemy) return;

	const float DoTDamage = FMath::Clamp(TargetArmorScuffLevel * 1.5f, 15.0f, 75.0f); // Higher scuff = higher poison penetration
	OnPoisonBladeExecuted.Broadcast(TargetEnemy, DoTDamage);

	UE_LOG(LogTemp, Warning, TEXT("UAshenGarrettPoisonBladeExecutionAbility: POISON BLADE EXECUTED -> Enemy '%s' | Scuff: %.1f | DoT: %.1f HP/sec."),
		*TargetEnemy->GetName(), TargetArmorScuffLevel, DoTDamage);
}
