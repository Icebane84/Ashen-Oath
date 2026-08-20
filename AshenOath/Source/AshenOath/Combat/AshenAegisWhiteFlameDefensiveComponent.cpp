// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 656: Ashen Aegis White Flame Defensive Component

#include "AshenAegisWhiteFlameDefensiveComponent.h"

UAshenAegisWhiteFlameDefensiveComponent::UAshenAegisWhiteFlameDefensiveComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CurrentStance = EAshenAegisDefensiveStance::None;
}

void UAshenAegisWhiteFlameDefensiveComponent::ActivateDefensiveStance(EAshenAegisDefensiveStance TargetStance)
{
	CurrentStance = TargetStance;
	float Cost = 0.0f;

	switch (CurrentStance)
	{
	case EAshenAegisDefensiveStance::GlancingDeflect: Cost = 0.0f; break; // Perfect Parry: 0 stamina
	case EAshenAegisDefensiveStance::HalfSwordBrace: Cost = 25.0f; break;
	case EAshenAegisDefensiveStance::CrownGuardCounter: Cost = 15.0f; break;
	case EAshenAegisDefensiveStance::MartyrGuard: Cost = 40.0f; break;
	default: Cost = 0.0f; break;
	}

	OnStanceActivated.Broadcast(CurrentStance, Cost);

	UE_LOG(LogTemp, Warning, TEXT("UAshenAegisWhiteFlameDefensiveComponent: DEFENSIVE STANCE ACTIVATED -> Stance %d | Stamina Cost: %.1f."),
		static_cast<int32>(CurrentStance), Cost);
}
