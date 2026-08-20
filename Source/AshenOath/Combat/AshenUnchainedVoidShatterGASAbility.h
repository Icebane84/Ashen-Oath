// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenUnchainedVoidShatterGASAbility.generated.h"

/**
 * UAshenUnchainedVoidShatterGASAbility
 * Unleashes void shockwave fracturing corrupted ground and staggering surrounding enemies.
 */
UCLASS()
class ASHENOATH_API UAshenUnchainedVoidShatterGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenUnchainedVoidShatterGASAbility();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Combat")
	float ShatterRadius = 650.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Combat")
	float ShatterBaseDamage = 180.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	bool ExecuteVoidShatter(FVector ImpactPoint);
};
