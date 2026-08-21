// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Tactics/AshenSquadTacticalSubsystem.h"
#include "Kismet/GameplayStatics.h"

UAshenSquadTacticalSubsystem::UAshenSquadTacticalSubsystem()
{
	bWheelOpen = false;
	DilationState = ETemporalDilationState::Realtime;
}

void UAshenSquadTacticalSubsystem::SetTacticalWheelOpen(bool bOpen)
{
	bWheelOpen = bOpen;

	if (bWheelOpen)
	{
		DilationState = ETemporalDilationState::TacticalSlowMo;
		OnTemporalDilationChanged.Broadcast(DilationState, 0.20f);
	}
	else
	{
		DilationState = ETemporalDilationState::Realtime;
		OnTemporalDilationChanged.Broadcast(DilationState, 1.00f);
	}

	OnTacticalWheelVisibilityChanged.Broadcast(bWheelOpen);
}

bool UAshenSquadTacticalSubsystem::DispatchSquadCommand(const FSquadCommandEntry& Command)
{
	if (Command.CommandType == ETacticalCommandType::None)
	{
		OnSquadCommandDispatched.Broadcast(Command, false);
		return false;
	}

	OnSquadCommandDispatched.Broadcast(Command, true);
	return true;
}
