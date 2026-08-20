// Copyright Phoenix Protocol. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenOath_SanityComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSanityChangedSignature, float, CurrentSanity, float, MaxSanity);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSanityDepletedSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInstabilitySpikeTriggeredSignature, float, InstabilityAmount);

/**
 * UAshenOath_SanityComponent
 * Psychological health tracker managing Sanity pools, Shadow Resonance,
 * and Instability events. Includes ticking passive recovery.
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenOath_SanityComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenOath_SanityComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/** Reduce sanity. Emits sanity_depleted if hitting 0. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Sanity")
	void SufferMentalDamage(float Amount);

	/** Add to current sanity. Clamps to MaxSanity. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Sanity")
	void HealSanity(float Amount);

	/** Consume shadow power, decreasing sanity and generating resonance and instability spikes. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Sanity")
	void ConsumeShadowPower(float BaseCost);

	// Getters and Setters
	UFUNCTION(BlueprintPure, Category = "AshenOath|Sanity")
	float GetCurrentSanity() const { return CurrentSanity; }

	UFUNCTION(BlueprintPure, Category = "AshenOath|Sanity")
	float GetMaxSanity() const { return MaxSanity; }

	UFUNCTION(BlueprintPure, Category = "AshenOath|Sanity")
	float GetCurrentResonance() const { return CurrentResonance; }

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Sanity")
	void SetCurrentSanity(float NewSanity);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Sanity")
	void SetCurrentResonance(float NewResonance);

public:
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Sanity|Events")
	FOnSanityChangedSignature OnSanityChanged;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Sanity|Events")
	FOnSanityDepletedSignature OnSanityDepleted;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Sanity|Events")
	FOnInstabilitySpikeTriggeredSignature OnInstabilitySpikeTriggered;

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sanity Settings", meta = (AllowPrivateAccess = "true"))
	float MaxSanity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sanity Settings", meta = (AllowPrivateAccess = "true"))
	float PassiveRecoveryRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sanity Settings", meta = (AllowPrivateAccess = "true"))
	float ShadowCostMultiplier;

	UPROPERTY(VisibleAnywhere, Category = "Sanity State")
	float CurrentSanity;

	UPROPERTY(VisibleAnywhere, Category = "Sanity State")
	float CurrentResonance;
};
