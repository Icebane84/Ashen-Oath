// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenNullZoneGASAbility.generated.h"

/**
 * UAshenNullZoneGASAbility
 * GAS ability allowing Kaelen to purge absorbed Null Zone corruption into a consecrated radial wave.
 */
UCLASS()
class ASHENOATH_API UAshenNullZoneGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenNullZoneGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Null Zone")
	float PurgeRadius = 800.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Null Zone")
	float BasePurgeDamage = 450.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Null Zone")
	bool UnleashPurgeShockwave(AActor* InstigatorActor, float CurrentIntegrationDebt);
};
