// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCANPragmaticAdaptationEvaluator.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPragmaticAdaptationEvaluatedSignature, float, PragmatismWeight, float, UtilityBonusMultiplier);

/**
 * UAshenCANPragmaticAdaptationEvaluator
 *
 * Component evaluating Garrett's can-pragmatic_adaptation anchor (utility over dogma).
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCANPragmaticAdaptationEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCANPragmaticAdaptationEvaluator();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|CANAnchors")
	void EvaluatePragmaticAdaptation(float TacticalNecessityWeight);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|CANAnchors|Events")
	FOnPragmaticAdaptationEvaluatedSignature OnAdaptationEvaluated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|CANAnchors")
	float ActivePragmatismWeight = 0.5f;
};
