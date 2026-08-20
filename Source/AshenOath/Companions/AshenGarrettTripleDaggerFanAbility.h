// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenGarrettTripleDaggerFanAbility.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDaggerFanExecutedSignature, int32, DaggersThrownCount, float, TotalRadialDamage);

/**
 * UAshenGarrettTripleDaggerFanAbility
 *
 * Ability throwing a radial dagger fan to disarm flanking enemies (PRS-001 Garrett Slice).
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenGarrettTripleDaggerFanAbility : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|GarrettAbilities")
	void ExecuteTripleDaggerFan(float BaseDamagePerDagger = 45.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|GarrettAbilities|Events")
	FOnDaggerFanExecutedSignature OnDaggerFanExecuted;
};
