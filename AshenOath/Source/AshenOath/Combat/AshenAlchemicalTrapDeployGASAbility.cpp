// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenAlchemicalTrapDeployGASAbility.h"

UAshenAlchemicalTrapDeployGASAbility::UAshenAlchemicalTrapDeployGASAbility()
{
	DeployTime = 0.75f;
	ArmingDelay = 0.50f;
}

bool UAshenAlchemicalTrapDeployGASAbility::DeployTrap(AActor* InstigatorActor, const FVector& TargetLocation, EAlchemicalItemType TrapType)
{
	if (!InstigatorActor) return false;
	UE_LOG(LogTemp, Warning, TEXT("UAshenAlchemicalTrapDeployGASAbility: Deployed Trap %d at %s (DeployTime: %.2fs)."),
		static_cast<int32>(TrapType), *TargetLocation.ToString(), DeployTime);
	return true;
}
