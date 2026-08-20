// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenCrownGuardCounterBindAbility.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCrownGuardCounterExecutedSignature, AActor*, TargetEnemy, bool, bDisarmSuccessful);

/**
 * UAshenCrownGuardCounterBindAbility
 *
 * Ability catching overhead strikes on crossguard for positional disarms (The Crown Guard Counter-Bind).
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenCrownGuardCounterBindAbility : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|CrownGuard")
	void ExecuteCrownGuardCounter(AActor* TargetEnemy);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|CrownGuard|Events")
	FOnCrownGuardCounterExecutedSignature OnCounterExecuted;
};
