// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenSoulUnificationDirectorComponent.h"

UAshenSoulUnificationDirectorComponent::UAshenSoulUnificationDirectorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CurrentResonance01 = 0.0f;
}

float UAshenSoulUnificationDirectorComponent::AddResonance(float Amount01)
{
	CurrentResonance01 = FMath::Clamp(CurrentResonance01 + Amount01, 0.0f, 1.0f);
	return CurrentResonance01;
}

void UAshenSoulUnificationDirectorComponent::ResetResonance()
{
	CurrentResonance01 = 0.0f;
}
