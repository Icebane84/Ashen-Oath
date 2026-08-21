// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Crafting/AshenSoulForgeTransmuterComponent.h"

UAshenSoulForgeTransmuterComponent::UAshenSoulForgeTransmuterComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FRunicSocketEntry UAshenSoulForgeTransmuterComponent::TransmuteBossShard(
	const FName& BossName,
	float ShardPower)
{
	FRunicSocketEntry Entry;
	Entry.RuneId = FName(*FString::Printf(TEXT("Rune_Core_%s"), *BossName.ToString()));
	Entry.SocketType = ERunicSocketType::BladeCore;
	Entry.AttunementTier = ESoulForgeAttunementTier::MasterForged;
	Entry.MassModifierKg = 35.0f * FMath::Clamp(ShardPower, 0.5f, 2.0f);
	Entry.PoiseMultiplier = 1.40f * FMath::Clamp(ShardPower, 0.8f, 1.5f);
	Entry.StaminaCostScalar = 1.15f;
	return Entry;
}

FRunicSocketEntry UAshenSoulForgeTransmuterComponent::TransmuteTraumaMemory(
	const FName& CompanionName,
	float IntegrationDebt)
{
	FRunicSocketEntry Entry;
	Entry.RuneId = FName(*FString::Printf(TEXT("Rune_Memory_%s"), *CompanionName.ToString()));
	Entry.SocketType = ERunicSocketType::HiltRelic;
	Entry.AttunementTier = (IntegrationDebt >= 0.70f) ? ESoulForgeAttunementTier::Overcharged : ESoulForgeAttunementTier::Resonant;
	Entry.MassModifierKg = -10.0f; // Lightens weapon grip
	Entry.PoiseMultiplier = 1.10f;
	Entry.StaminaCostScalar = 0.85f; // Decreases somatic stamina drain
	return Entry;
}
