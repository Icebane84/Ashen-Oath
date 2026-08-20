// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenPyreCleaveGASAbility.generated.h"

/**
 * UAshenPyreCleaveGASAbility
 * Devastating white flame greatsword heavy strike dealing 1800.0 holy-kinetic damage and disintegrating Null-Zone abominations.
 */
UCLASS()
class ASHENOATH_API UAshenPyreCleaveGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenPyreCleaveGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | WhiteFlame")
	float PyreCleaveDamage = 1800.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | WhiteFlame")
	bool ExecutePyreCleave(AActor* TargetActor);
};
