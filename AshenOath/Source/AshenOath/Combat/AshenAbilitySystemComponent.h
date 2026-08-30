// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffectTypes.h"
#include "AshenAbilitySystemComponent.generated.h"

class UAshenSoulPublisher;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAshenSanityChanged, float, NewSanity);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAshenPoiseChanged, float, NewPoise);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAshenStaminaChanged, float, NewStamina);

/**
 * UAshenAbilitySystemComponent
 *
 * Core Gameplay Ability System component for Ashen Oath characters.
 * Bridges attribute changes (Sanity, Poise, Stamina) directly into
 * the canonical Single Source of Truth (UAshenSoulPublisher) without
 * leaking or directly modifying derived somatic signals.
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	UAshenAbilitySystemComponent();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath|Abilities")
	void AcquireAbility(TSubclassOf<UGameplayAbility> AbilityToAcquire);

	/** Handles internal attribute change data and propagates canonical state */
	void OnAttributeChange(const FOnAttributeChangeData& Data);

	/** Routes gameplay effect applications to world expression and audio subsystems */
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath|Abilities")
	void OnGameplayEffectAppliedToSelf(UAbilitySystemComponent* Source, const FGameplayEffectSpec& SpecApplied, FActiveGameplayEffectHandle ActiveHandle);

	// -------------------------------------------------------------------------
	// KINETIC ATTRIBUTE MANIPULATION (Directly routes to UAshenSoulPublisher)
	// -------------------------------------------------------------------------

	/** Applies psychic damage/sanity loss, increasing canonical Dysregulation & Corruption */
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath|Combat")
	void ApplySanityDamage(float Amount);

	/** Applies poise strain from heavy guard impact, increasing canonical Integration Debt */
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath|Combat")
	void ApplyPoiseStrain(float Amount);

	/** Drains stamina, triggering cardiac haptic drag when exhausted */
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath|Combat")
	void ApplyStaminaDrain(float Amount);

	UFUNCTION(BlueprintPure, Category = "Ashen Oath|Combat")
	float GetCurrentSanity() const { return CurrentSanity; }

	UFUNCTION(BlueprintPure, Category = "Ashen Oath|Combat")
	float GetCurrentPoise() const { return CurrentPoise; }

	UFUNCTION(BlueprintPure, Category = "Ashen Oath|Combat")
	float GetCurrentStamina() const { return CurrentStamina; }

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath|Events")
	FOnAshenSanityChanged OnSanityChanged;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath|Events")
	FOnAshenPoiseChanged OnPoiseChanged;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath|Events")
	FOnAshenStaminaChanged OnStaminaChanged;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Attributes", meta = (ClampMin = "0.0", ClampMax = "1000.0"))
	float MaxSanity = 100.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen Oath|Attributes")
	float CurrentSanity = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Attributes", meta = (ClampMin = "0.0", ClampMax = "1000.0"))
	float MaxPoise = 100.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen Oath|Attributes")
	float CurrentPoise = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Attributes", meta = (ClampMin = "0.0", ClampMax = "1000.0"))
	float MaxStamina = 100.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen Oath|Attributes")
	float CurrentStamina = 100.0f;

private:
	/** Cached helper to safely locate the Soul Publisher subsystem */
	UAshenSoulPublisher* GetSoulPublisher() const;
};
