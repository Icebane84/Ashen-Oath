// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenWrathNecroticCounterGASAbility.generated.h"

/**
 * UAshenWrathNecroticCounterGASAbility
 * Wrath choice ability: uses kinetic momentum to unleash an unrefined dark counter-slam, shredding enemy armor while increasing taint by +5.0.
 */
UCLASS()
class ASHENOATH_API UAshenWrathNecroticCounterGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenWrathNecroticCounterGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Combat")
	float CounterDamage = 950.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Combat")
	float TaintCorruptionSpike = 5.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	bool ExecuteWrathCounter(AActor* KaelenActor, AActor* TargetEnemy);
};
