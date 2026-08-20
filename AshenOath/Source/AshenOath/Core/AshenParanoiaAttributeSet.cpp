// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 236: Ashen Paranoia Attribute Set

#include "AshenParanoiaAttributeSet.h"
#include "GameplayEffectExtension.h"

UAshenParanoiaAttributeSet::UAshenParanoiaAttributeSet()
	: ParanoiaLevel(0.0f)
	, Sanity(100.0f)
	, SpiritualCold(0.0f)
	, StaminaRegenPenalty(1.0f)
{
}

void UAshenParanoiaAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetParanoiaLevelAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.0f, 100.0f);
	}
	else if (Attribute == GetSanityAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.0f, 100.0f);
	}
	else if (Attribute == GetSpiritualColdAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.0f, 1.0f);
	}
}

void UAshenParanoiaAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute == GetParanoiaLevelAttribute())
	{
		const float CurrentParanoia = GetParanoiaLevel();
		SetSanity(FMath::Max(100.0f - CurrentParanoia, 0.0f));

		if (CurrentParanoia >= 100.0f)
		{
			UE_LOG(LogTemp, Warning, TEXT("UAshenParanoiaAttributeSet: Target Sanity depleted! Creeping Paranoia is fully active at 100%%!"));
		}
	}

	if (Data.EvaluatedData.Attribute == GetSpiritualColdAttribute())
	{
		SetStaminaRegenPenalty(1.0f - (GetSpiritualCold() * 0.50f));
	}
}
