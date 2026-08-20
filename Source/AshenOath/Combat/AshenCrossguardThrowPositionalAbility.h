// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenCrossguardThrowPositionalAbility.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCrossguardThrowExecutedSignature, AActor*, TargetEnemy, FVector, ThrowTargetLocation);

/**
 * UAshenCrossguardThrowPositionalAbility
 *
 * Ability executing positional throws/disarms following a successful Crown Guard Counter-Bind (PRS-001 Combat Blueprint).
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenCrossguardThrowPositionalAbility : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|CrossguardThrow")
	void ExecuteCrossguardThrow(AActor* TargetEnemy, FVector ThrowDirection);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|CrossguardThrow|Events")
	FOnCrossguardThrowExecutedSignature OnThrowExecuted;
};
