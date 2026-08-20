// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenBurningSteelOilComponent.generated.h"

/**
 * UAshenBurningSteelOilComponent
 * Modulates Garrett's twin cutlasses when coated in Burning Steel Oil (+35 Posture Damage, strips 15% physical armor for 6.0s).
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenBurningSteelOilComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenBurningSteelOilComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Alchemy")
	bool bIsBladesIgnited = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Alchemy")
	float PostureDamageBonus = 35.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Alchemy")
	float ArmorStripPercentage = 0.15f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Alchemy")
	void ApplyOilToBlades(float DurationSeconds);
};
