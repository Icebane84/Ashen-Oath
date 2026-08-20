// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenEldrinsGraceGASAbility.generated.h"

/**
 * UAshenEldrinsGraceGASAbility
 * Gameplay Ability executing "Eldrin's Grace" agility & multi-parry stance unlocked via Inner World Memory Battle integration.
 */
UCLASS()
class ASHENOATH_API UAshenEldrinsGraceGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenEldrinsGraceGASAbility();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | GAS")
	float GraceParryWindowMultiplier = 2.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | GAS")
	bool ActivateEldrinsGraceStance();
};
