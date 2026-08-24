// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Orchestration/AshenScenario6MasterBridge.h"

UAshenScenario6MasterBridge::UAshenScenario6MasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenScenario6MasterBridge::BroadcastScenario6Update(
	float Frostbite,
	float HearthIgnition,
	bool bInWarmth)
{
	EFrostbiteSeverity Severity = EFrostbiteSeverity::Normal;
	if (Frostbite > 0.75f)
	{
		Severity = EFrostbiteSeverity::Hypothermia;
	}
	else if (Frostbite > 0.50f)
	{
		Severity = EFrostbiteSeverity::SlowingChill;
	}
	else if (Frostbite > 0.25f)
	{
		Severity = EFrostbiteSeverity::NumbFingers;
	}

	OnFrostbiteBroadcaster.Broadcast(Frostbite, Severity);
}
