// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenScenario6MissionSubsystem.h"

UAshenScenario6MissionSubsystem::UAshenScenario6MissionSubsystem()
{
	CurrentState.BlizzardWeather = EBlizzardIntensity::DrivingSnow;
	CurrentState.FrostbiteSeverity = EFrostbiteSeverity::Normal;
	CurrentState.AmbientTemperatureCelsius = -15.0f;
	CurrentState.FrostbiteGauge = 0.0f;
	CurrentState.HearthIgnitionProgress = 0.0f;
	CurrentState.HearthState = EHearthSanctuaryState::FrozenExtinguished;
	CurrentState.bInCompanionWarmthRadius = false;
}

void UAshenScenario6MissionSubsystem::SetBlizzardIntensity(EBlizzardIntensity NewIntensity)
{
	CurrentState.BlizzardWeather = NewIntensity;

	switch (NewIntensity)
	{
	case EBlizzardIntensity::CalmChill:
		CurrentState.AmbientTemperatureCelsius = -5.0f;
		break;
	case EBlizzardIntensity::DrivingSnow:
		CurrentState.AmbientTemperatureCelsius = -15.0f;
		break;
	case EBlizzardIntensity::SevereBlizzard:
		CurrentState.AmbientTemperatureCelsius = -25.0f;
		break;
	case EBlizzardIntensity::WhiteoutSurge:
		CurrentState.AmbientTemperatureCelsius = -35.0f;
		break;
	}

	OnBlizzardWeatherChanged.Broadcast(NewIntensity, CurrentState.AmbientTemperatureCelsius);
}

void UAshenScenario6MissionSubsystem::ChannelHearthIgnition(float DeltaProgress)
{
	CurrentState.HearthIgnitionProgress = FMath::Clamp(CurrentState.HearthIgnitionProgress + DeltaProgress, 0.0f, 1.0f);

	if (CurrentState.HearthIgnitionProgress >= 1.0f)
	{
		CurrentState.HearthState = EHearthSanctuaryState::SanctifiedBlaze;
		OnSanctifiedHearthComplete.Broadcast(true);
	}
	else if (CurrentState.HearthIgnitionProgress > 0.0f)
	{
		CurrentState.HearthState = EHearthSanctuaryState::KindlingIgnition;
	}

	OnHearthIgnitionProgressChanged.Broadcast(CurrentState.HearthIgnitionProgress, CurrentState.HearthState);
}

void UAshenScenario6MissionSubsystem::ApplyFrostbiteDelta(float DeltaFrostbite, bool bInWarmthZone)
{
	CurrentState.bInCompanionWarmthRadius = bInWarmthZone;

	// Warmth zones reverse frostbite accumulation
	const float EffectiveDelta = bInWarmthZone ? -FMath::Abs(DeltaFrostbite) * 1.5f : DeltaFrostbite;
	CurrentState.FrostbiteGauge = FMath::Clamp(CurrentState.FrostbiteGauge + EffectiveDelta, 0.0f, 1.0f);

	EFrostbiteSeverity NewSeverity = EFrostbiteSeverity::Normal;
	if (CurrentState.FrostbiteGauge > 0.75f)
	{
		NewSeverity = EFrostbiteSeverity::Hypothermia;
	}
	else if (CurrentState.FrostbiteGauge > 0.50f)
	{
		NewSeverity = EFrostbiteSeverity::SlowingChill;
	}
	else if (CurrentState.FrostbiteGauge > 0.25f)
	{
		NewSeverity = EFrostbiteSeverity::NumbFingers;
	}

	CurrentState.FrostbiteSeverity = NewSeverity;
	OnFrostbiteUpdated.Broadcast(CurrentState.FrostbiteGauge, NewSeverity);
}
