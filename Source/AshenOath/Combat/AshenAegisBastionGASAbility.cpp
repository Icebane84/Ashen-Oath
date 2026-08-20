// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenAegisBastionGASAbility.h"

UAshenAegisBastionGASAbility::UAshenAegisBastionGASAbility()
{
	MaxBarrierAbsorption = 500.0f;
	PoiseMultiplier = 2.0f;
}

bool UAshenAegisBastionGASAbility::DeployBastionBarrier(AActor* InstigatorActor)
{
	if (!InstigatorActor) return false;
	UE_LOG(LogTemp, Warning, TEXT("UAshenAegisBastionGASAbility: Deployed Aegis Bastion Barrier (Absorb: %.1f, Poise Multiplier: %.1fx)."),
		MaxBarrierAbsorption, PoiseMultiplier);
	return true;
}
