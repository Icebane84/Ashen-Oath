// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenBurdenOfCommandComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnBurdenOfCommandEvaluatedSignature, float, BurdenScore, float, PartyResolveMultiplier);

/**
 * UAshenBurdenOfCommandComponent
 *
 * Component tracking Kaelen's leadership weight and party resolve multipliers.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenBurdenOfCommandComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenBurdenOfCommandComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|BurdenOfCommand")
	void EvaluateBurdenOfCommand(float LeadershipWeight);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|BurdenOfCommand")
	void AccrueCommandStrain(float Strain);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|BurdenOfCommand")
	void RestAndRelieveStrain(float Amount);

	UFUNCTION(BlueprintPure, Category = "AshenOath|BurdenOfCommand")
	bool IsRefusingCommands() const { return ActiveBurdenScore >= 90.0f; }

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|BurdenOfCommand|Events")
	FOnBurdenOfCommandEvaluatedSignature OnBurdenEvaluated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|BurdenOfCommand")
	float ActiveBurdenScore = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|BurdenOfCommand")
	float CalculatedPartyResolveMultiplier = 1.0f;
};
