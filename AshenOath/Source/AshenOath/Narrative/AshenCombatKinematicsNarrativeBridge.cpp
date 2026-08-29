// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenCombatKinematicsNarrativeBridge.h"

UAshenCombatKinematicsNarrativeBridge::UAshenCombatKinematicsNarrativeBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FText UAshenCombatKinematicsNarrativeBridge::FormatKinematicsBark(
	EPoiseStaggerState StaggerState,
	bool bPerfectRiposte) const
{
	if (bPerfectRiposte)
	{
		return FText::FromString(TEXT("[Garrett]: 'BEAUTIFUL DEFLECTION! Take his head!'"));
	}

	switch (StaggerState)
	{
	case EPoiseStaggerState::PoiseBroken:
		return FText::FromString(TEXT("[Serafina]: 'KAELEN'S GUARD IS SHATTERED! Covering you now!'"));
	case EPoiseStaggerState::UnsteadyGuard:
		return FText::FromString(TEXT("[Garrett]: 'Stance is slipping, wielder! Keep your footing!'"));
	case EPoiseStaggerState::SolidGuard:
	default:
		return FText::FromString(TEXT("[Kaelen]: 'Solid stance. Ready for their charge.'"));
	}
}
