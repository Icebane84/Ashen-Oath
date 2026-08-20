// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 757: Ashen Malakor Void Smash Boss Phase Controller

#include "AshenMalakorVoidSmashBossPhaseController.h"

UAshenMalakorVoidSmashBossPhaseController::UAshenMalakorVoidSmashBossPhaseController()
{
	PrimaryComponentTick.bCanEverTick = false;
	TotalSmashesExecuted = 0;
}

void UAshenMalakorVoidSmashBossPhaseController::ExecuteVoidSmash(FVector ImpactTarget, float BaseSmashDamage)
{
	TotalSmashesExecuted++;
	OnVoidSmashExecuted.Broadcast(ImpactTarget, BaseSmashDamage);

	UE_LOG(LogTemp, Warning, TEXT("UAshenMalakorVoidSmashBossPhaseController: MALAKOR VOID SMASH EXECUTED -> Target: (%s) | Damage: %.1f HP (Total: %d)."),
		*ImpactTarget.ToString(), BaseSmashDamage, TotalSmashesExecuted);
}
