// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCANEmpathicBurnoutComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnEmpathicBurnoutEvaluatedSignature, float, BurnoutLevel, float, HealingEfficiencyMultiplier);

/**
 * UAshenCANEmpathicBurnoutComponent
 *
 * Component evaluating Serafina's Empathic Burnout CAN anchor (can-empathic_burnout).
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCANEmpathicBurnoutComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCANEmpathicBurnoutComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|CANAnchors")
	void AccrueEmpathicBurnout(float DeltaBurnout);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|CANAnchors|Events")
	FOnEmpathicBurnoutEvaluatedSignature OnBurnoutEvaluated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|CANAnchors")
	float ActiveBurnoutLevel = 0.0f;
};
