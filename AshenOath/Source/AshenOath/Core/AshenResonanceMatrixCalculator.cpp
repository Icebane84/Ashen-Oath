// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenResonanceMatrixCalculator.h"

UAshenResonanceMatrixCalculator::UAshenResonanceMatrixCalculator()
{
	PrimaryComponentTick.bCanEverTick = false;
	CurrentSynergyMultiplier = 1.0f;
	ActiveSynergyCount = 0;
}

void UAshenResonanceMatrixCalculator::BeginPlay()
{
	Super::BeginPlay();
}

float UAshenResonanceMatrixCalculator::CalculateResonanceMultiplier(const TSet<FName>& UnlockedPerks)
{
	CurrentSynergyMultiplier = 1.0f;
	ActiveSynergyCount = 0;

	// Pairwise Synergy 1: UnshakeableStance + VitalResonance -> +15% Synergy Multiplier
	if (UnlockedPerks.Contains(FName("Perk_UnshakeableStance")) && UnlockedPerks.Contains(FName("Perk_VitalResonance")))
	{
		CurrentSynergyMultiplier += 0.15f;
		ActiveSynergyCount++;
	}

	// Pairwise Synergy 2: AlchemicalPurity + EmpathicResonance -> +15% Synergy Multiplier
	if (UnlockedPerks.Contains(FName("Perk_AlchemicalPurity")) && UnlockedPerks.Contains(FName("Perk_EmpathicResonance")))
	{
		CurrentSynergyMultiplier += 0.15f;
		ActiveSynergyCount++;
	}

	OnResonanceSynergyCalculated.Broadcast(CurrentSynergyMultiplier, ActiveSynergyCount);
	UE_LOG(LogTemp, Log, TEXT("UAshenResonanceMatrixCalculator: Calculated Synergy Multiplier: %.2fx (%d active synergies)."),
		CurrentSynergyMultiplier, ActiveSynergyCount);

	return CurrentSynergyMultiplier;
}
