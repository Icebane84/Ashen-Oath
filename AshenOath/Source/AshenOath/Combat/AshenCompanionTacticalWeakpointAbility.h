// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenCompanionTacticalWeakpointAbility.generated.h"

/**
 * UAshenCompanionTacticalWeakpointAbility
 * Gameplay Ability exploiting weak-point frame data learned directly from Garrett's journal marginalia notes.
 */
UCLASS()
class ASHENOATH_API UAshenCompanionTacticalWeakpointAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenCompanionTacticalWeakpointAbility();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | GAS")
	float WeakpointDamageMultiplier = 2.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | GAS")
	bool ExecuteWeakpointFlankStrike(AActor* TargetEnemy);
};
