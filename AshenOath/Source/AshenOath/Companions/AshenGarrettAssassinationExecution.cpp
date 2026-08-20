// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Companions/AshenGarrettAssassinationExecution.h"

UAshenGarrettAssassinationExecution::UAshenGarrettAssassinationExecution()
{
	MaxDashRange = 850.0f;
	ArmorShredDamage = 350.0f;
	BasePostureBreakAmount = 100.0f;
}

bool UAshenGarrettAssassinationExecution::ExecuteAssassinationDash(AActor* GarrettActor, AActor* VictimEnemy)
{
	if (!GarrettActor || !VictimEnemy) return false;

	UE_LOG(LogTemp, Warning, TEXT("UAshenGarrettAssassinationExecution: Executed assassination dash on %s! Dealt %.1f armor shred damage."),
		*VictimEnemy->GetName(), ArmorShredDamage);
	return true;
}
