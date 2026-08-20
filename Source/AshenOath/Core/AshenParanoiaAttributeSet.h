// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "AshenParanoiaAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * UAshenParanoiaAttributeSet
 *
 * GAS Attribute Set managing ParanoiaLevel, Sanity, SpiritualCold, and StaminaRegenPenalty.
 */
UCLASS()
class ASHENOATH_API UAshenParanoiaAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UAshenParanoiaAttributeSet();

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	UPROPERTY(BlueprintReadOnly, Category = "AshenOath|Attributes|Paranoia")
	FGameplayAttributeData ParanoiaLevel;
	ATTRIBUTE_ACCESSORS(UAshenParanoiaAttributeSet, ParanoiaLevel)

	UPROPERTY(BlueprintReadOnly, Category = "AshenOath|Attributes|Paranoia")
	FGameplayAttributeData Sanity;
	ATTRIBUTE_ACCESSORS(UAshenParanoiaAttributeSet, Sanity)

	UPROPERTY(BlueprintReadOnly, Category = "AshenOath|Attributes|Paranoia")
	FGameplayAttributeData SpiritualCold;
	ATTRIBUTE_ACCESSORS(UAshenParanoiaAttributeSet, SpiritualCold)

	UPROPERTY(BlueprintReadOnly, Category = "AshenOath|Attributes|Paranoia")
	FGameplayAttributeData StaminaRegenPenalty;
	ATTRIBUTE_ACCESSORS(UAshenParanoiaAttributeSet, StaminaRegenPenalty)
};
