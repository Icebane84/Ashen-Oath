// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenSeedAlchemicalCaltropsGASAbility.generated.h"

/**
 * UAshenSeedAlchemicalCaltropsGASAbility
 * GAS ability allowing Garrett to seed a 400uu corridor with thermal-ignitable alchemical caltrops.
 */
UCLASS()
class ASHENOATH_API UAshenSeedAlchemicalCaltropsGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenSeedAlchemicalCaltropsGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Alchemy")
	float SeedingRadiusUnits = 400.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Alchemy")
	bool SeedCaltropCorridor(AActor* GarrettActor, FVector SeedCenterLocation);
};
