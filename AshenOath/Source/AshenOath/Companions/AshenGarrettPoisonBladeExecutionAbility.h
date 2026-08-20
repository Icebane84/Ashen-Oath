// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenGarrettPoisonBladeExecutionAbility.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPoisonBladeExecutedSignature, AActor*, TargetEnemy, float, PoisonDoTDamagePerSec);

/**
 * UAshenGarrettPoisonBladeExecutionAbility
 *
 * GAS Ability applying poison damage over time to armor-scuffed targets (PRS-001 Garrett Slice).
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenGarrettPoisonBladeExecutionAbility : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|GarrettAbilities")
	void ExecutePoisonBlade(AActor* TargetEnemy, float TargetArmorScuffLevel);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|GarrettAbilities|Events")
	FOnPoisonBladeExecutedSignature OnPoisonBladeExecuted;
};
