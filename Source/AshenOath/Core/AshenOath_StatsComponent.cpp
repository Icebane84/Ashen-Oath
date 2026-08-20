// Copyright Phoenix Protocol. All rights reserved.

#include "AshenOath_StatsComponent.h"
#include "AshenOath_HealthComponent.h"
#include "GameFramework/Actor.h"

UAshenOath_StatsComponent::UAshenOath_StatsComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	Vitality = 10;
	Strength = 10;
	Dexterity = 10;
	Level = 1;
	Experience = 0;
	XpRequirementBase = 100;
	HealthComponent = nullptr;
}

void UAshenOath_StatsComponent::BeginPlay()
{
	Super::BeginPlay();

	if (GetOwner())
	{
		HealthComponent = GetOwner()->FindComponentByClass<UAshenOath_HealthComponent>();
	}

	SyncMaxHealth();
}

void UAshenOath_StatsComponent::SetVitality(int32 NewVitality)
{
	Vitality = FMath::Max(0, NewVitality);
	SyncMaxHealth();
}

void UAshenOath_StatsComponent::SetStrength(int32 NewStrength)
{
	Strength = FMath::Max(0, NewStrength);
}

void UAshenOath_StatsComponent::SetDexterity(int32 NewDexterity)
{
	Dexterity = FMath::Max(0, NewDexterity);
}

int32 UAshenOath_StatsComponent::GetXpRequirement() const
{
	return Level * XpRequirementBase;
}

void UAshenOath_StatsComponent::AddXp(int32 Amount)
{
	if (Amount <= 0) return;

	Experience += Amount;
	OnXpGained.Broadcast(Amount, Experience);

	while (Experience >= GetXpRequirement())
	{
		LevelUp();
	}
}

float UAshenOath_StatsComponent::GetMaxHealthFormula() const
{
	return 100.0f + (Vitality * 15.0f);
}

float UAshenOath_StatsComponent::GetAttackPowerFormula() const
{
	return 10.0f + (Strength * 2.5f);
}

void UAshenOath_StatsComponent::LevelUp()
{
	Experience -= GetXpRequirement();
	Level += 1;
	OnLevelUp.Broadcast(Level);

	SyncMaxHealth();

	if (HealthComponent)
	{
		// Heal player to full on Level Up
		HealthComponent->Heal(HealthComponent->GetMaxHealth());
	}
}

void UAshenOath_StatsComponent::SyncMaxHealth()
{
	if (HealthComponent)
	{
		HealthComponent->SetMaxHealth(GetMaxHealthFormula());
	}
}

void UAshenOath_StatsComponent::LoadStatsState(int32 InLevel, int32 InXP)
{
	Level = FMath::Max(1, InLevel);
	Experience = FMath::Max(0, InXP);
	SyncMaxHealth();
}
