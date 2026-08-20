// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenAtmosphericPurgeGASAbility.generated.h"

/**
 * UAshenAtmosphericPurgeGASAbility
 * GAS ability unleashing a 1000.0uu purification blast that purges local toxicity and grants +50% respirator efficiency for 15.0s.
 */
UCLASS()
class ASHENOATH_API UAshenAtmosphericPurgeGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenAtmosphericPurgeGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Combat")
	float PurgeRadius = 1000.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Combat")
	float PurgeBuffDuration = 15.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Combat")
	float ResolveCost = 20.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	bool UnleashAtmosphericPurge(AActor* InstigatorActor);
};
