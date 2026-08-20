// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenRealitySunderGASAbility.generated.h"

/**
 * UAshenRealitySunderGASAbility
 * High-risk dimensional cleave unleashing 650.0 radial damage in exchange for +0.15 Integration Debt.
 */
UCLASS()
class ASHENOATH_API UAshenRealitySunderGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenRealitySunderGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Combat")
	float SunderBaseDamage = 650.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Combat")
	float IntegrationDebtCost = 0.15f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Combat")
	float CleaveRadius = 750.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	bool UnleashRealitySunder(AActor* InstigatorActor);
};
