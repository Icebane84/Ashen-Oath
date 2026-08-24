// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenScenario8MissionSubsystem.h"

UAshenScenario8MissionSubsystem::UAshenScenario8MissionSubsystem()
{
	DarknessState.TorchFuelPercent01 = 1.0f;
	DarknessState.EffectiveLightRadiusUU = 800.0f;
	DarknessState.DarknessAccuracyPenalty01 = 0.0f;
	DarknessState.SonarActiveRadiusUU = 0.0f;
	DarknessState.LightState = ELightEnvironmentState::RadiantIlluminated;
	DarknessState.bInRadiantFlare = false;
}

void UAshenScenario8MissionSubsystem::SetTorchFuel(float NewFuel01, bool bFlareActive)
{
	DarknessState.TorchFuelPercent01 = FMath::Clamp(NewFuel01, 0.0f, 1.0f);
	DarknessState.bInRadiantFlare = bFlareActive;

	if (bFlareActive)
	{
		DarknessState.EffectiveLightRadiusUU = 1200.0f;
		DarknessState.LightState = ELightEnvironmentState::RadiantIlluminated;
		DarknessState.DarknessAccuracyPenalty01 = 0.0f;
	}
	else
	{
		DarknessState.EffectiveLightRadiusUU = FMath::Clamp(100.0f + (700.0f * DarknessState.TorchFuelPercent01), 100.0f, 800.0f);

		if (DarknessState.EffectiveLightRadiusUU > 600.0f)
		{
			DarknessState.LightState = ELightEnvironmentState::RadiantIlluminated;
			DarknessState.DarknessAccuracyPenalty01 = 0.0f;
		}
		else if (DarknessState.EffectiveLightRadiusUU > 250.0f)
		{
			DarknessState.LightState = ELightEnvironmentState::FlickeringDim;
			DarknessState.DarknessAccuracyPenalty01 = 0.15f;
		}
		else if (DarknessState.EffectiveLightRadiusUU > 120.0f)
		{
			DarknessState.LightState = ELightEnvironmentState::GloomPerimeter;
			DarknessState.DarknessAccuracyPenalty01 = 0.35f;
		}
		else
		{
			DarknessState.LightState = ELightEnvironmentState::PitchBlackDarkness;
			DarknessState.DarknessAccuracyPenalty01 = 0.60f;
		}
	}

	OnTorchFuelChanged.Broadcast(DarknessState.TorchFuelPercent01, DarknessState.EffectiveLightRadiusUU);
	OnLightEnvironmentChanged.Broadcast(DarknessState.LightState, DarknessState.DarknessAccuracyPenalty01);
}

void UAshenScenario8MissionSubsystem::EmitEcholocationPing(
	EEcholocationPulseType PulseType,
	const FVector& Origin)
{
	float Radius = 350.0f;
	switch (PulseType)
	{
	case EEcholocationPulseType::BladeClangEcho:
		Radius = 900.0f;
		break;
	case EEcholocationPulseType::GroundSlamSonar:
		Radius = 1800.0f;
		break;
	case EEcholocationPulseType::RadiantFlarePulse:
		Radius = 1200.0f;
		break;
	default:
		Radius = 350.0f;
		break;
	}

	DarknessState.SonarActiveRadiusUU = Radius;
	OnEcholocationPingEmitted.Broadcast(PulseType, Origin, Radius);
}
