// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenAtmosphericConductivityEvaluatorComponent.h"

UAshenAtmosphericConductivityEvaluatorComponent::UAshenAtmosphericConductivityEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenAtmosphericConductivityEvaluatorComponent::BeginPlay() { Super::BeginPlay(); }

float UAshenAtmosphericConductivityEvaluatorComponent::CalculateResonanceMultiplier(EWeatherState Weather) const
{
	float Multiplier = 1.0f;
	if (Weather == EWeatherState::PsychicStorm)
	{
		Multiplier = 1.20f; // +20% Resonance / Lightning Conduction
	}
	else if (Weather == EWeatherState::VoidMiasma)
	{
		Multiplier = 1.10f; // +10% Decay Conduction
	}
	return Multiplier;
}

float UAshenAtmosphericConductivityEvaluatorComponent::CalculateMovementFrictionMultiplier(EWeatherState Weather) const
{
	float Friction = 1.0f;
	if (Weather == EWeatherState::AshBlizzard)
	{
		Friction = 0.70f; // Heavy drag / low friction sliding
	}
	else if (Weather == EWeatherState::VoidMiasma)
	{
		Friction = 0.85f;
	}
	return Friction;
}
