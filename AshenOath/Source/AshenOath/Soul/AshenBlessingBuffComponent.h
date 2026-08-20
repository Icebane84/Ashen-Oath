// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenBlessingBuffComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnBlessingBuffAppliedSignature, FName, BlessingID, float, StatModifierPercent);

/**
 * UAshenBlessingBuffComponent
 *
 * Component applying active bonfire blessing stat buffs to player pawn.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenBlessingBuffComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenBlessingBuffComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|BlessingBuff")
	void ApplyBlessingBuff(FName BlessingID, float StatModifierPercent = 15.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|BlessingBuff|Events")
	FOnBlessingBuffAppliedSignature OnBlessingBuffApplied;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|BlessingBuff")
	FName ActiveBlessingID;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|BlessingBuff")
	float ActiveStatModifierPercent = 0.0f;
};
