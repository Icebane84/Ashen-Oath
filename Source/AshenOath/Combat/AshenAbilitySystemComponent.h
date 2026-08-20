// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffectTypes.h"
#include "AshenAbilitySystemComponent.generated.h"

/**
 * UAshenAbilitySystemComponent
 *
 * Core Gameplay Ability System component for Ashen Oath characters.
 */
UCLASS()
class ASHENOATH_API UAshenAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	UAshenAbilitySystemComponent();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath|Abilities")
	void AcquireAbility(TSubclassOf<UGameplayAbility> AbilityToAcquire);

	void OnAttributeChange(const FOnAttributeChangeData& Data);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath|Abilities")
	void OnGameplayEffectApplied(UAbilitySystemComponent* Source, const FGameplayEffectSpec& SpecApplied, FActiveGameplayEffectHandle ActiveHandle);
};
