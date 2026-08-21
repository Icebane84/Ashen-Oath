// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenReluctantKnifeEvaluatorComponent.h"

UAshenReluctantKnifeEvaluatorComponent::UAshenReluctantKnifeEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

EReluctantKnifeEthos UAshenReluctantKnifeEvaluatorComponent::EvaluateValeriusStance(
	float BattleDurationSeconds,
	float RitualHealthLost) const
{
	if (RitualHealthLost >= 0.50f || BattleDurationSeconds >= 120.0f)
	{
		return EReluctantKnifeEthos::HardenedResignation;
	}
	else if (RitualHealthLost >= 0.25f || BattleDurationSeconds >= 60.0f)
	{
		return EReluctantKnifeEthos::DesperateContainment;
	}
	return EReluctantKnifeEthos::ControlledMitigation;
}

FText UAshenReluctantKnifeEvaluatorComponent::EvaluateValeriusDialogueBark(EReluctantKnifeEthos Ethos) const
{
	switch (Ethos)
	{
	case EReluctantKnifeEthos::HardenedResignation:
		return FText::FromString(TEXT("[Elder Valerius]: 'Forgive me, Kaelen... The cage must hold, even if the vessel cracks.'"));
	case EReluctantKnifeEthos::DesperateContainment:
		return FText::FromString(TEXT("[Elder Valerius]: 'Hold the circle! If the flame dies here, the entire valley burns!'"));
	case EReluctantKnifeEthos::ControlledMitigation:
	default:
		return FText::FromString(TEXT("[Elder Valerius]: 'Focus your breathing, boy. We do what we must—not what is easy.'"));
	}
}
