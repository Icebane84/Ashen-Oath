// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenWhisperingSicknessEvaluatorComponent.h"

UAshenWhisperingSicknessEvaluatorComponent::UAshenWhisperingSicknessEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenWhisperingSicknessEvaluatorComponent::EvaluateSicknessOverlayWeight(
	float VaultContaminationPercent) const
{
	return FMath::Clamp(VaultContaminationPercent * 0.85f, 0.0f, 0.85f);
}
