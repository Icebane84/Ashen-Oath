// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 802: Ashen Aegis Crown Guard Counter Bind Ability

#include "AshenAegisCrownGuardCounterBindAbility.h"

void UAshenAegisCrownGuardCounterBindAbility::ExecuteCrownGuardCounterBind(AActor* TargetEnemy, float BasePommelDamage)
{
	OnCrownGuardExecuted.Broadcast(TargetEnemy, BasePommelDamage);

	UE_LOG(LogTemp, Warning, TEXT("UAshenAegisCrownGuardCounterBindAbility: CROWN GUARD (KRON) COUNTER-BIND EXECUTED -> Target: '%s' | Pommel Strike Damage: %.1f HP."),
		TargetEnemy ? *TargetEnemy->GetName() : TEXT("Enemy"), BasePommelDamage);
}
