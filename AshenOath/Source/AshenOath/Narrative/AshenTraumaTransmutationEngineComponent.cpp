// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenTraumaTransmutationEngineComponent.h"

UAshenTraumaTransmutationEngineComponent::UAshenTraumaTransmutationEngineComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FTransmutedTraitReward UAshenTraumaTransmutationEngineComponent::ForgeTrait(
	FName TraitName,
	FGameplayTag TraitTag,
	float Bonus)
{
	FTransmutedTraitReward Reward;
	Reward.TraitId = FGuid::NewGuid().ToString(EGuidFormats::DigitsWithHyphensLower);
	Reward.TraitName = TraitName;
	Reward.TraitTag = TraitTag;
	Reward.StatBonusScalar = Bonus;
	Reward.FlavorDescription = FString::Printf(TEXT("Forged through campfire reflection on %s"), *TraitName.ToString());

	UnlockedTraits.Add(Reward);
	return Reward;
}
