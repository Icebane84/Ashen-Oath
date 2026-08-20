// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenAegisCrownGuardCounterBindAbility.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCrownGuardCounterBindExecutedSignature, AActor*, TargetEnemy, float, PommelStrikeDamage);

/**
 * UAshenAegisCrownGuardCounterBindAbility
 *
 * Ability executing Kron Crown Guard counter-bind, catching overhead strikes and pommel-striking (PRS-001 Combat Blueprint V5.0).
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenAegisCrownGuardCounterBindAbility : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|CrownGuard")
	void ExecuteCrownGuardCounterBind(AActor* TargetEnemy, float BasePommelDamage = 200.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|CrownGuard|Events")
	FOnCrownGuardCounterBindExecutedSignature OnCrownGuardExecuted;
};
