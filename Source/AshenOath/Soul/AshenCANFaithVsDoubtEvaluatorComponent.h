// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCANFaithVsDoubtEvaluatorComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnFaithVsDoubtEvaluatedSignature, float, FaithLevel, float, DoubtLevel);

/**
 * UAshenCANFaithVsDoubtEvaluatorComponent
 *
 * Component evaluating Kaelen's Faith vs Doubt CAN anchor (can-faith_vs_doubt).
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCANFaithVsDoubtEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCANFaithVsDoubtEvaluatorComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|CANAnchors")
	void EvaluateFaithVsDoubt(float DeltaFaith, float DeltaDoubt);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|CANAnchors|Events")
	FOnFaithVsDoubtEvaluatedSignature OnFaithVsDoubtEvaluated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|CANAnchors")
	float ActiveFaithLevel = 0.5f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|CANAnchors")
	float ActiveDoubtLevel = 0.5f;
};
