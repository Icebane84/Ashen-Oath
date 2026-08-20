// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCANTriageBurdenEvaluatorComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTriageBurdenEvaluatedSignature, float, TriageWeight, float, CompanionSacrificeCost);

/**
 * UAshenCANTriageBurdenEvaluatorComponent
 *
 * Component evaluating Garrett's Triage Burden CAN anchor (can-triage_burden).
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCANTriageBurdenEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCANTriageBurdenEvaluatorComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|CANAnchors")
	void EvaluateTriageBurden(float DeltaTriageWeight);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|CANAnchors|Events")
	FOnTriageBurdenEvaluatedSignature OnTriageBurdenEvaluated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|CANAnchors")
	float ActiveTriageWeight = 0.0f;
};
