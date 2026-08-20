// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "AshenAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * UAshenAttributeSet
 *
 * Core Gameplay Attribute Set for Ashen Oath characters.
 */
UCLASS()
class ASHENOATH_API UAshenAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UAshenAttributeSet();

	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Health")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UAshenAttributeSet, Health)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Health")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UAshenAttributeSet, MaxHealth)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Stamina")
	FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS(UAshenAttributeSet, Stamina)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Stamina")
	FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS(UAshenAttributeSet, MaxStamina)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Sanity")
	FGameplayAttributeData Sanity;
	ATTRIBUTE_ACCESSORS(UAshenAttributeSet, Sanity)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Sanity")
	FGameplayAttributeData MaxSanity;
	ATTRIBUTE_ACCESSORS(UAshenAttributeSet, MaxSanity)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Damage")
	FGameplayAttributeData Damage;
	ATTRIBUTE_ACCESSORS(UAshenAttributeSet, Damage)
};
