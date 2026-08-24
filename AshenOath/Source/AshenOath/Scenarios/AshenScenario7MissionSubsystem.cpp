// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenScenario7MissionSubsystem.h"

UAshenScenario7MissionSubsystem::UAshenScenario7MissionSubsystem()
{
	ThermodynamicsState.AmbientCalderaTempC = 45.0f;
	ThermodynamicsState.HeatExhaustion01 = 0.0f;
	ThermodynamicsState.StaminaDrainMultiplier = 1.0f;
	ThermodynamicsState.BladeTemperedHeatC = 20.0f;
	ThermodynamicsState.BladeState = ETemperedBladeState::ColdSteel;
	ThermodynamicsState.SurgePhase = ECalderaSurgePhase::DormantCalm;
	ThermodynamicsState.bInsideCoolingMist = false;
}

void UAshenScenario7MissionSubsystem::SetCalderaTemperature(float NewTempC, bool bInCoolingZone)
{
	ThermodynamicsState.AmbientCalderaTempC = NewTempC;
	ThermodynamicsState.bInsideCoolingMist = bInCoolingZone;

	if (bInCoolingZone)
	{
		ThermodynamicsState.HeatExhaustion01 = FMath::Clamp(ThermodynamicsState.HeatExhaustion01 - 0.05f, 0.0f, 1.0f);
	}
	else
	{
		const float DeltaHeat = FMath::Max(0.0f, (NewTempC - 35.0f) / 400.0f);
		ThermodynamicsState.HeatExhaustion01 = FMath::Clamp(ThermodynamicsState.HeatExhaustion01 + DeltaHeat, 0.0f, 1.0f);
	}

	ThermodynamicsState.StaminaDrainMultiplier = 1.0f + (1.0f * ThermodynamicsState.HeatExhaustion01);

	// Classify tier
	EHeatExhaustionTier Tier = EHeatExhaustionTier::Comfortable;
	if (ThermodynamicsState.HeatExhaustion01 >= 0.90f)
	{
		Tier = EHeatExhaustionTier::Incinerating;
	}
	else if (ThermodynamicsState.HeatExhaustion01 >= 0.60f)
	{
		Tier = EHeatExhaustionTier::Heatstroke;
	}
	else if (ThermodynamicsState.HeatExhaustion01 >= 0.30f)
	{
		Tier = EHeatExhaustionTier::Dehydrated;
	}

	OnCalderaTemperatureChanged.Broadcast(NewTempC, ThermodynamicsState.HeatExhaustion01);
	OnHeatExhaustionTierChanged.Broadcast(Tier);
}

void UAshenScenario7MissionSubsystem::AdvanceMagmaSurgePhase(
	ECalderaSurgePhase NewPhase,
	const FVector& SurgeLocation)
{
	ThermodynamicsState.SurgePhase = NewPhase;
	OnMagmaSurgeStateChanged.Broadcast(NewPhase, SurgeLocation);
}

void UAshenScenario7MissionSubsystem::SetBladeTempering(
	float BladeTempC,
	ETemperedBladeState NewState)
{
	ThermodynamicsState.BladeTemperedHeatC = BladeTempC;
	ThermodynamicsState.BladeState = NewState;
	OnBladeTemperingStateChanged.Broadcast(NewState, BladeTempC);
}
