// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenScenario2MissionSubsystem.h"

UAshenScenario2MissionSubsystem::UAshenScenario2MissionSubsystem()
{
}

bool UAshenScenario2MissionSubsystem::RegisterTrap(const FGarrettTrapPlacementData& NewTrap)
{
	if (NewTrap.TrapId.IsNone())
	{
		return false;
	}

	if (DeployedTraps.Contains(NewTrap.TrapId))
	{
		return false;
	}

	DeployedTraps.Add(NewTrap.TrapId, NewTrap);
	OnTrapDeployed.Broadcast(NewTrap.TrapId, NewTrap.TrapType);
	return true;
}

void UAshenScenario2MissionSubsystem::RecordEnemyFunneled(const FName& EnemyId)
{
	FunnelContext.EnemiesFunneledIntoRavine++;
	OnEnemyFunneledToHazard.Broadcast(EnemyId, FunnelContext.EnemiesFunneledIntoRavine);
}
