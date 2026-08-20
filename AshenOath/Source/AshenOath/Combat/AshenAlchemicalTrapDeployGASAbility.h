// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "Crafting/AshenAlchemicalCraftingTypes.h"
#include "AshenAlchemicalTrapDeployGASAbility.generated.h"

/**
 * UAshenAlchemicalTrapDeployGASAbility
 * GAS ability allowing Kaelen/Garrett to physically deploy Gloomwood tripwires or sulfur daze canisters in tactical combat arenas.
 */
UCLASS()
class ASHENOATH_API UAshenAlchemicalTrapDeployGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenAlchemicalTrapDeployGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Trap")
	float DeployTime = 0.75f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Trap")
	float ArmingDelay = 0.50f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Trap")
	bool DeployTrap(AActor* InstigatorActor, const FVector& TargetLocation, EAlchemicalItemType TrapType);
};
