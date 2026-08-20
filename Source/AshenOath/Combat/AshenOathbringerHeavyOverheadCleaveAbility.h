// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenOathbringerHeavyOverheadCleaveAbility.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHeavyOverheadCleaveExecutedSignature, AActor*, TargetEnemy, float, CleaveDamageDealt);

/**
 * UAshenOathbringerHeavyOverheadCleaveAbility
 *
 * Ability executing a massive downward cleave that shatters enemy shields (PRS-001 Oathbringer Slice).
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenOathbringerHeavyOverheadCleaveAbility : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|OathbringerAbilities")
	void ExecuteHeavyOverheadCleave(AActor* TargetEnemy, float BaseCleaveDamage = 450.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|OathbringerAbilities|Events")
	FOnHeavyOverheadCleaveExecutedSignature OnOverheadCleaveExecuted;
};
