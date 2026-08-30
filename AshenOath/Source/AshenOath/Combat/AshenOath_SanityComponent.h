// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenOath_SanityComponent.generated.h"

class UAshenAbilitySystemComponent;
class UAshenSoulPublisher;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSanityChangedSignature, float, CurrentSanity, float, MaxSanity);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSanityDepletedSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInstabilitySpikeTriggeredSignature, float, InstabilityAmount);

/**
 * UAshenOath_SanityComponent
 *
 * Lightweight legacy-compatible view adapter over UAshenAbilitySystemComponent
 * and UAshenSoulPublisher. Eliminates private split-brain sanity pools while
 * preserving BP-callable interfaces for existing gameplay blueprints.
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenOath_SanityComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenOath_SanityComponent();

	virtual void BeginPlay() override;

	/** Routes mental damage to UAshenAbilitySystemComponent & Soul Publisher */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Sanity")
	void SufferMentalDamage(float Amount);

	/** Restores sanity, committing negative dysregulation/corruption deltas */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Sanity")
	void HealSanity(float Amount);

	/** Consumes shadow power, triggering instability deltas */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Sanity")
	void ConsumeShadowPower(float BaseCost);

	UFUNCTION(BlueprintPure, Category = "AshenOath|Sanity")
	float GetCurrentSanity() const;

	UFUNCTION(BlueprintPure, Category = "AshenOath|Sanity")
	float GetMaxSanity() const { return MaxSanity; }

	UFUNCTION(BlueprintPure, Category = "AshenOath|Sanity")
	float GetCurrentResonance() const;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Sanity")
	void SetCurrentSanity(float NewSanity);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Sanity")
	void SetCurrentResonance(float NewResonance);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Sanity|Events")
	FOnSanityChangedSignature OnSanityChanged;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Sanity|Events")
	FOnSanityDepletedSignature OnSanityDepleted;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Sanity|Events")
	FOnInstabilitySpikeTriggeredSignature OnInstabilitySpikeTriggered;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sanity Settings")
	float MaxSanity = 100.0f;

private:
	UAshenAbilitySystemComponent* GetOwnerASC() const;
	UAshenSoulPublisher* GetSoulPublisher() const;
};
