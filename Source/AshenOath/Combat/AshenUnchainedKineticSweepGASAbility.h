// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenUnchainedKineticSweepGASAbility.generated.h"

/**
 * UAshenUnchainedKineticSweepGASAbility
 * Kaelen's indiscriminate 180° heavy greatsword cleave dealing 1100.0 damage to enemies and companions alike.
 */
UCLASS()
class ASHENOATH_API UAshenUnchainedKineticSweepGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenUnchainedKineticSweepGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Combat")
	float SweepDamage = 1100.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Combat")
	float SweepArcDegrees = 180.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	bool ExecuteIndiscriminateSweep(AActor* UnchainedKaelenActor);
};
