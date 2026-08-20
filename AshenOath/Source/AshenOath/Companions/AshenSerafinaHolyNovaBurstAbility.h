// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenSerafinaHolyNovaBurstAbility.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHolyNovaBurstExecutedSignature, FVector, BurstCenterLocation, float, KnockbackImpulsePower);

/**
 * UAshenSerafinaHolyNovaBurstAbility
 *
 * Ability bursting holy nova light to knock back approaching void abominations (PRS-001 Serafina Slice).
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenSerafinaHolyNovaBurstAbility : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|SerafinaAbilities")
	void ExecuteHolyNovaBurst(FVector Location, float KnockbackPower = 600.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|SerafinaAbilities|Events")
	FOnHolyNovaBurstExecutedSignature OnHolyNovaExecuted;
};
