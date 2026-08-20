// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenMemoryBattleGASAbility.generated.h"

/**
 * UAshenMemoryBattleGASAbility
 * GAS ability unleashing radiant catharsis strikes and trauma purging fields within the Mindscape arena.
 */
UCLASS()
class ASHENOATH_API UAshenMemoryBattleGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenMemoryBattleGASAbility();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Memory GAS")
	float CatharsisBaseDamage = 280.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Memory GAS")
	bool UnleashCatharsisBurst(float ImprintWeightMultiplier);
};
