// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenTripartiteCinematicFinisherGASAbility.generated.h"

/**
 * UAshenTripartiteCinematicFinisherGASAbility
 * Trio GAS ability executing a staggered boss with a cinematic combo strike (2500.0 holy-kinetic damage).
 */
UCLASS()
class ASHENOATH_API UAshenTripartiteCinematicFinisherGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenTripartiteCinematicFinisherGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Combat")
	float FinisherDamage = 2500.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	bool ExecuteTripartiteFinisher(AActor* BossActor);
};
