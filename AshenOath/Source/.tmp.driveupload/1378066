// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenOverheadCrushGASAbility.generated.h"

/**
 * UAshenOverheadCrushGASAbility
 * High-impact boss slam forcing Kaelen to decide between solo Glass Shield absorption (massive debt) or Trio synchronized parry.
 */
UCLASS()
class ASHENOATH_API UAshenOverheadCrushGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenOverheadCrushGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Combat")
	float BaseCrushDamage = 900.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Combat")
	float SoloAbsorptionDebtPenalty = 35.0f; // +35% debt if absorbed alone

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	bool ExecuteOverheadCrush(AActor* TargetActor, bool bWasSynchronizedParry);
};
