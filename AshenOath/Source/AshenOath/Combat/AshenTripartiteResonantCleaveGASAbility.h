// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenTripartiteResonantCleaveGASAbility.generated.h"

/**
 * UAshenTripartiteResonantCleaveGASAbility
 * Devastating trio synchronized finisher unlocked exclusively via the Lens of Grace (1400 DMG, clears 30% Integration Debt).
 */
UCLASS()
class ASHENOATH_API UAshenTripartiteResonantCleaveGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenTripartiteResonantCleaveGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Combat")
	float BaseFinisherDamage = 1400.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Combat")
	float DebtClearingPercentage = 0.30f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	bool ExecuteResonantCleave(AActor* TargetActor);
};
