// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenOath_HealthComponent.generated.h"

// Multicast delegate signatures
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHealthChangedSignature, float, CurrentHealth, float, MaxHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDamagedSignature, float, Amount, AActor*, DamageSource);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealedSignature, float, Amount);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDiedSignature);

/**
 * UAshenOath_HealthComponent
 * Core health management, healing, and invincibility tracking component.
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenOath_HealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UAshenOath_HealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	/** Getters & Setters for health properties */
	UFUNCTION(BlueprintPure, Category = "AshenOath|Health")
	float GetCurrentHealth() const;

	UFUNCTION(BlueprintPure, Category = "AshenOath|Health")
	float GetMaxHealth() const;

	UFUNCTION(BlueprintPure, Category = "AshenOath|Health")
	float GetHealthPercent() const { return (MaxHealth > 0.0f) ? (CurrentHealth / MaxHealth) : 0.0f; }

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Health")
	void SetMaxHealth(float NewMaxHealth);

	UFUNCTION(BlueprintPure, Category = "AshenOath|Health")
	float GetInvincibilityTime() const { return InvincibilityTime; }

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Health")
	void SetInvincibilityTime(float NewInvincibilityTime);

	UFUNCTION(BlueprintPure, Category = "AshenOath|Health")
	bool IsInvincible() const { return bIsInvincible; }

	/** Apply damage. Returns the actual amount of damage taken. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Health")
	float ReceiveDamage(float Amount, AActor* DamageSource = nullptr);

	/** Apply healing. Returns the actual amount healed. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Health")
	float Heal(float Amount);

public:
	/** Broadcast when current health changes */
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Health|Events")
	FOnHealthChangedSignature OnHealthChanged;

	/** Broadcast when damage is applied */
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Health|Events")
	FOnDamagedSignature OnDamaged;

	/** Broadcast when healing is applied */
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Health|Events")
	FOnHealedSignature OnHealed;

	/** Broadcast when health drops to or below zero */
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Health|Events")
	FOnDiedSignature OnDied;

private:
	void EndInvincibility();
	void HandleHealthChanged(const struct FOnAttributeChangeData& Data) const;
	void HandleMaxHealthChanged(const struct FOnAttributeChangeData& Data) const;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health", meta = (AllowPrivateAccess = "true"))
	float MaxHealth = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health", meta = (AllowPrivateAccess = "true"))
	float CurrentHealth = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Health", meta = (AllowPrivateAccess = "true"))
	float InvincibilityTime;

	bool bIsInvincible;

	FTimerHandle InvincibilityTimerHandle;

	UPROPERTY(Transient)
	TWeakObjectPtr<class UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(Transient)
	TWeakObjectPtr<const class UAshenAttributeSet> AttributeSet;
};
