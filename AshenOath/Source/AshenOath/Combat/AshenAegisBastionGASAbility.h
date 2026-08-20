// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenAegisBastionGASAbility.generated.h"

/**
 * UAshenAegisBastionGASAbility
 * GAS ability rooting player, deploying a frontal kinetic barrier absorbing 500.0 damage and deflecting projectiles.
 */
UCLASS()
class ASHENOATH_API UAshenAegisBastionGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenAegisBastionGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Combat")
	float MaxBarrierAbsorption = 500.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Combat")
	float PoiseMultiplier = 2.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	bool DeployBastionBarrier(AActor* InstigatorActor);
};
