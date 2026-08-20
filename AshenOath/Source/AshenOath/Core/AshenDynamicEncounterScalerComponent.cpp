// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 401: Ashen Dynamic Encounter Scaler Component

#include "AshenDynamicEncounterScalerComponent.h"

UAshenDynamicEncounterScalerComponent::UAshenDynamicEncounterScalerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenDynamicEncounterScalerComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenDynamicEncounterScalerComponent::ScaleEncounterDifficulty(float CombatEfficiencyRating, float PlayerSanity)
{
	float DiffMult = 1.0f + (CombatEfficiencyRating / 100.0f) * 0.5f;
	if (PlayerSanity < 30.0f) DiffMult += 0.25f;

	int32 BonusElites = (DiffMult >= 1.5f) ? 2 : (DiffMult >= 1.25f ? 1 : 0);
	OnEncounterScaled.Broadcast(DiffMult, BonusElites);

	UE_LOG(LogTemp, Warning, TEXT("UAshenDynamicEncounterScalerComponent: ENCOUNTER SCALED -> Diff Multiplier: %.2fx, Bonus Elites: %d."),
		DiffMult, BonusElites);
}
