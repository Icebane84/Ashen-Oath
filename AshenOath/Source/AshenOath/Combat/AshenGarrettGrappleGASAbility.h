// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenGarrettGrappleGASAbility.generated.h"

/**
 * UAshenGarrettGrappleGASAbility
 * GAS Ability triggering grapple projectile and acceleration pull.
 */
UCLASS()
class ASHENOATH_API UAshenGarrettGrappleGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenGarrettGrappleGASAbility();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | GAS")
	bool ActivateGarrettGrapple(FVector TargetPos);
};
