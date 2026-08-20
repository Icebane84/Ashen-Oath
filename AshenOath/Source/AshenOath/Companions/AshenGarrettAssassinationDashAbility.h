// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenGarrettAssassinationDashAbility.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAssassinationDashExecutedSignature, AActor*, TargetEnemy, float, DashDamageDealt);

/**
 * UAshenGarrettAssassinationDashAbility
 *
 * Ability executing high-velocity dash strikes against staggered targets (PRS-001 Garrett Slice).
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenGarrettAssassinationDashAbility : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|GarrettAbilities")
	void ExecuteAssassinationDash(AActor* TargetEnemy, float BaseDashDamage = 180.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|GarrettAbilities|Events")
	FOnAssassinationDashExecutedSignature OnDashExecuted;
};
