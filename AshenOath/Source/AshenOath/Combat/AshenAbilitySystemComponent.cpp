// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenAbilitySystemComponent.h"
#include "AshenGameplayAbility.h"

UAshenAbilitySystemComponent::UAshenAbilitySystemComponent()
{
}

void UAshenAbilitySystemComponent::AcquireAbility(TSubclassOf<UGameplayAbility> AbilityToAcquire)
{
	if (AbilityToAcquire)
	{
		GiveAbility(FGameplayAbilitySpec(AbilityToAcquire, 1));
	}
}

void UAshenAbilitySystemComponent::OnAttributeChange(const FOnAttributeChangeData& Data)
{
	// Placeholder for logic when an attribute changes
}

void UAshenAbilitySystemComponent::OnGameplayEffectApplied(UAbilitySystemComponent* Source, const FGameplayEffectSpec& SpecApplied, FActiveGameplayEffectHandle ActiveHandle)
{
	// Placeholder for logic when a gameplay effect is applied
}
