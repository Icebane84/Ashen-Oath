// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenCombatHitboxImprintIntegratorComponent.h"

UAshenCombatHitboxImprintIntegratorComponent::UAshenCombatHitboxImprintIntegratorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenCombatHitboxImprintIntegratorComponent::RecordHitImprint(float Damage, bool bFatal)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenCombatHitboxImprintIntegratorComponent: Combat hit imprint recorded (Damage: %.1f, Fatal: %s)"),
		Damage, bFatal ? TEXT("TRUE") : TEXT("FALSE"));
}
