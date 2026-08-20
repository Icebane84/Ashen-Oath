// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenApplyBurningSteelOilGASAbility.generated.h"

/**
 * UAshenApplyBurningSteelOilGASAbility
 * GAS ability allowing Garrett to apply Burning Steel Oil to his twin cutlasses for 15.0s of thermal posture-breaking combat.
 */
UCLASS()
class ASHENOATH_API UAshenApplyBurningSteelOilGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenApplyBurningSteelOilGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Alchemy")
	float OilDurationSeconds = 15.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Alchemy")
	bool ApplyOilToWeapons(AActor* GarrettActor);
};
