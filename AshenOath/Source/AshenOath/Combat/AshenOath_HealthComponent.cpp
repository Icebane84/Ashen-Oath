// Fill out your copyright notice in the Description page of Project Settings.

#include "AshenOath_HealthComponent.h"
#include "AshenAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffectTypes.h"
#include "AshenCharacterInterface.h"
#include "AbilitySystemInterface.h"
// TimerManager.h include removed as it is not used directly

// Sets default values for this component's properties
UAshenOath_HealthComponent::UAshenOath_HealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	MaxHealth = 100.0f;
	CurrentHealth = 100.0f;
	InvincibilityTime = 0.5f;
	bIsInvincible = false;
}

// Called when the game starts
void UAshenOath_HealthComponent::BeginPlay()
{
	Super::BeginPlay();
	if (CurrentHealth <= 0.0f && MaxHealth > 0.0f)
	{
		CurrentHealth = MaxHealth;
	}
	if (const AActor* Owner = GetOwner())
	{
		if (const IAbilitySystemInterface* ASI = Cast<IAbilitySystemInterface>(Owner))
		{
			AbilitySystemComponent = ASI->GetAbilitySystemComponent();
		}
	}

	if (AbilitySystemComponent.IsValid())
	{
		AttributeSet = AbilitySystemComponent->GetSet<UAshenAttributeSet>();
		if (AttributeSet.IsValid())
		{
			AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UAshenAttributeSet::GetHealthAttribute()).AddUObject(this, &UAshenOath_HealthComponent::HandleHealthChanged);
			AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UAshenAttributeSet::GetMaxHealthAttribute()).AddUObject(this, &UAshenOath_HealthComponent::HandleMaxHealthChanged);
		}
	}
}

void UAshenOath_HealthComponent::HandleHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue, GetMaxHealth());

	if (Data.NewValue <= 0.0f && Data.OldValue > 0.0f)
	{
		OnDied.Broadcast();
	}
}

void UAshenOath_HealthComponent::HandleMaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(GetCurrentHealth(), Data.NewValue);
}

float UAshenOath_HealthComponent::GetCurrentHealth() const
{
	return AttributeSet.IsValid() ? AttributeSet->GetHealth() : CurrentHealth;
}

float UAshenOath_HealthComponent::GetMaxHealth() const
{
	return AttributeSet.IsValid() ? AttributeSet->GetMaxHealth() : MaxHealth;
}

void UAshenOath_HealthComponent::SetMaxHealth(float NewMaxHealth)
{
	// This is now controlled by GameplayEffects, but we can provide a helper.
	if (!AbilitySystemComponent.IsValid()) return;
	AbilitySystemComponent->ApplyModToAttribute(UAshenAttributeSet::GetMaxHealthAttribute(), EGameplayModOp::Override, NewMaxHealth);
}

void UAshenOath_HealthComponent::SetInvincibilityTime(float NewInvincibilityTime)
{
	InvincibilityTime = FMath::Max(0.0f, NewInvincibilityTime);
}

float UAshenOath_HealthComponent::ReceiveDamage(float Amount, AActor* DamageSource)
{
	if (Amount <= 0.0f) return 0.0f;

	if (AbilitySystemComponent.IsValid() && AttributeSet.IsValid())
	{
		UGameplayEffect* DamageEffect = NewObject<UGameplayEffect>();
		DamageEffect->DurationPolicy = EGameplayEffectDurationType::Instant;
		
		int32 Idx = DamageEffect->Modifiers.Num();
		DamageEffect->Modifiers.SetNum(Idx + 1);
		FGameplayModifierInfo& ModifierInfo = DamageEffect->Modifiers[Idx];
		ModifierInfo.Attribute = UAshenAttributeSet::GetDamageAttribute();
		ModifierInfo.ModifierOp = EGameplayModOp::Additive;
		ModifierInfo.ModifierMagnitude = FGameplayEffectModifierMagnitude(FScalableFloat(Amount));

		FGameplayEffectContextHandle ContextHandle = AbilitySystemComponent->MakeEffectContext();
		ContextHandle.AddInstigator(DamageSource, GetOwner());

		AbilitySystemComponent->ApplyGameplayEffectToSelf(DamageEffect, 1.0f, ContextHandle);
		OnDamaged.Broadcast(Amount, DamageSource);
		return Amount;
	}

	// Fallback: Direct standalone health subtraction when GAS is not active
	float OldHealth = CurrentHealth;
	CurrentHealth = FMath::Max(0.0f, CurrentHealth - Amount);
	
	UE_LOG(LogTemp, Warning, TEXT("UAshenOath_HealthComponent: %s took %.1f damage (HP: %.1f -> %.1f)"),
		*GetOwner()->GetName(), Amount, OldHealth, CurrentHealth);

	OnDamaged.Broadcast(Amount, DamageSource);
	OnHealthChanged.Broadcast(CurrentHealth, MaxHealth);

	if (CurrentHealth <= 0.0f && OldHealth > 0.0f)
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenOath_HealthComponent: %s DIED! Broadcasting OnDied."), *GetOwner()->GetName());
		OnDied.Broadcast();
	}

	return Amount;
}

float UAshenOath_HealthComponent::Heal(float Amount)
{
	if (!AbilitySystemComponent.IsValid() || !AttributeSet.IsValid() || Amount <= 0.0f)
	{
		return 0.0f;
	}

	AbilitySystemComponent->ApplyModToAttribute(UAshenAttributeSet::GetHealthAttribute(), EGameplayModOp::Additive, Amount);
	OnHealed.Broadcast(Amount);
	return Amount;
}

void UAshenOath_HealthComponent::EndInvincibility()
{
	bIsInvincible = false;
}
