// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenScenario9MissionSubsystem.h"

UAshenScenario9MissionSubsystem::UAshenScenario9MissionSubsystem()
{
	CitadelState.GravityScale = 0.35f;
	CitadelState.WindSpeedMps = 15.0f;
	CitadelState.WindDirection = FVector(1.0f, 0.0f, 0.0f);
	CitadelState.BridgeStability01 = 1.0f;
	CitadelState.GravityTier = EVoidGravityZoneTier::LowVoidGravity;
	CitadelState.WindState = EWindShearGustState::CalmBreeze;
	CitadelState.BridgeStatus = ETelekineticBridgeStatus::StableActive;
}

void UAshenScenario9MissionSubsystem::SetGravityTier(EVoidGravityZoneTier NewTier)
{
	CitadelState.GravityTier = NewTier;
	switch (NewTier)
	{
	case EVoidGravityZoneTier::StandardGravity:
		CitadelState.GravityScale = 1.00f;
		break;
	case EVoidGravityZoneTier::LowVoidGravity:
		CitadelState.GravityScale = 0.35f;
		break;
	case EVoidGravityZoneTier::ZeroGOrbitalDrift:
		CitadelState.GravityScale = 0.10f;
		break;
	case EVoidGravityZoneTier::HyperGravitonWell:
		CitadelState.GravityScale = 1.50f;
		break;
	default:
		CitadelState.GravityScale = 0.35f;
		break;
	}

	OnGravityZoneChanged.Broadcast(CitadelState.GravityTier, CitadelState.GravityScale);
}

void UAshenScenario9MissionSubsystem::SetWindShearGust(
	EWindShearGustState State,
	float SpeedMps,
	const FVector& Direction)
{
	CitadelState.WindState = State;
	CitadelState.WindSpeedMps = FMath::Clamp(SpeedMps, 0.0f, 60.0f);
	CitadelState.WindDirection = Direction.GetSafeNormal();

	OnWindShearGustTriggered.Broadcast(State, CitadelState.WindSpeedMps, CitadelState.WindDirection);
}

void UAshenScenario9MissionSubsystem::SetBridgeStatus(
	ETelekineticBridgeStatus Status,
	float Stability01)
{
	CitadelState.BridgeStatus = Status;
	CitadelState.BridgeStability01 = FMath::Clamp(Stability01, 0.0f, 1.0f);

	OnTelekineticBridgeStateChanged.Broadcast(Status, CitadelState.BridgeStability01);
}
