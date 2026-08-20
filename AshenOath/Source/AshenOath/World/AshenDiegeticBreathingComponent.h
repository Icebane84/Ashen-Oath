// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticBreathingComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnDiegeticBreathingUpdatedSignature, float, BreathingRateHz, float, FatiguePercent, FName, AudioBarkTag);

/**
 * UAshenDiegeticBreathingComponent
 *
 * Procedural breathing component projecting stamina fatigue into 3 distinct layers:
 * Layer 1 (Combat): Stamina regen multiplier.
 * Layer 2 (Audio/VFX): Panting MetaSound bark tag & chest mesh expansion scale.
 * Layer 3 (AI): Noise emission penalty increasing AI threat perception.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticBreathingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDiegeticBreathingComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|DiegeticBreathing")
	void UpdateBreathingFatigue(float CurrentStamina, float MaxStamina);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|DiegeticBreathing|Events")
	FOnDiegeticBreathingUpdatedSignature OnBreathingUpdated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|DiegeticBreathing")
	float CalculatedBreathingRateHz = 0.5f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|DiegeticBreathing")
	float CalculatedFatiguePercent = 0.0f;
};
