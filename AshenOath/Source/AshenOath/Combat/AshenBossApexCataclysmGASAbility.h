// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenBossApexCataclysmGASAbility.generated.h"

/**
 * UAshenBossApexCataclysmGASAbility
 * Ultimate boss GAS ability triggering arena-wide void cataclysm (1200.0 DMG in 1500uu) requiring White Flame resolution to survive.
 */
UCLASS()
class ASHENOATH_API UAshenBossApexCataclysmGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenBossApexCataclysmGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Boss")
	float CataclysmDamage = 1200.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Boss")
	float BlastRadiusUnits = 1500.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Boss")
	bool UnleashApexCataclysm(FVector Origin);
};
