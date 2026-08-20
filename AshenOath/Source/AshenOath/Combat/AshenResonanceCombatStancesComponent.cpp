// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 312: Ashen Resonance Combat Stances Component

#include "AshenResonanceCombatStancesComponent.h"

UAshenResonanceCombatStancesComponent::UAshenResonanceCombatStancesComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CurrentStance = EAshenCombatStance::GuardianStance;
}

void UAshenResonanceCombatStancesComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenResonanceCombatStancesComponent::SwitchStance(EAshenCombatStance NewStance)
{
	CurrentStance = NewStance;

	float SpeedMult = 1.0f;
	switch (NewStance)
	{
		case EAshenCombatStance::ResonantShatterStance:
			SpeedMult = 1.15f;
			break;
		case EAshenCombatStance::VoidVesselStance:
			SpeedMult = 1.30f;
			break;
		default:
			break;
	}

	OnCombatStanceChanged.Broadcast(NewStance, SpeedMult);

	UE_LOG(LogTemp, Warning, TEXT("UAshenResonanceCombatStancesComponent: COMBAT STANCE SWITCHED -> Stance %d (Frame Speed: %.2fx)."),
		(int32)NewStance, SpeedMult);
}
