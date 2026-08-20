// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticFacialExpressionComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnFacialExpressionUpdatedSignature, float, PainGrimaceWeight, float, ExhaustionWeight);

/**
 * UAshenDiegeticFacialExpressionComponent
 *
 * Procedural facial expression blending component scaling pain/grimace morph targets with health and fatigue.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticFacialExpressionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDiegeticFacialExpressionComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|FacialExpression")
	void UpdateFacialMorphWeights(float CurrentHealth, float MaxHealth, float FatiguePercent);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|FacialExpression|Events")
	FOnFacialExpressionUpdatedSignature OnFacialExpressionUpdated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|FacialExpression")
	float CalculatedPainGrimaceWeight = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|FacialExpression")
	float CalculatedExhaustionWeight = 0.0f;
};
