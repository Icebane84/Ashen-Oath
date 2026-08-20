// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSoulStateVectorComponent.h"
#include "AshenFalseConfidenceDeceptionComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnFalseConfidenceDeceptionStateChangedSignature, bool, bIsDeceptionActive, float, DeceptionIntensity);

/**
 * UAshenFalseConfidenceDeceptionComponent
 *
 * False Confidence Protocol engine (UMB-SYS-005).
 * Reverses damage feedback, increases attack speed, removes stagger frames, forces rigid posture, and triggers companion hesitation & enemy panic.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenFalseConfidenceDeceptionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenFalseConfidenceDeceptionComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|FalseConfidence")
	void EvaluateFalseConfidenceState(const FAshenSoulStateVector& SoulVector);

	UFUNCTION(BlueprintPure, Category = "AshenOath|FalseConfidence")
	bool IsDeceptionActive() const { return bDeceptionActive; }

	UFUNCTION(BlueprintPure, Category = "AshenOath|FalseConfidence")
	float GetAttackSpeedMultiplier() const { return AttackSpeedMultiplier; }

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|FalseConfidence|Events")
	FOnFalseConfidenceDeceptionStateChangedSignature OnDeceptionStateChanged;

private:
	bool bDeceptionActive = false;
	float AttackSpeedMultiplier = 1.0f;
	float DeceptionIntensity = 0.0f;
};
