// Copyright Phoenix Protocol. All rights reserved.

#include "AshenOath_DirectorSubsystem.h"
#include "GameFramework/Pawn.h"
#include "QuestSystem.h"
#include "VFXManager.h"

void UAshenOath_DirectorSubsystem::SetPlayerPawn(APawn* InPlayerPawn)
{
	PlayerPawn = InPlayerPawn;
}

void UAshenOath_DirectorSubsystem::SetQuestSystem(UQuestSystem* InQuestSystem)
{
	QuestSystem = InQuestSystem;
}

void UAshenOath_DirectorSubsystem::SetVFXManager(UVFXManager* InVFXManager)
{
	VFXManager = InVFXManager;
}

APawn* UAshenOath_DirectorSubsystem::GetPlayerPawn() const
{
	return PlayerPawn.IsValid() ? PlayerPawn.Get() : nullptr;
}

UQuestSystem* UAshenOath_DirectorSubsystem::GetQuestSystem() const
{
	return QuestSystem.IsValid() ? QuestSystem.Get() : nullptr;
}

UVFXManager* UAshenOath_DirectorSubsystem::GetVFXManager() const
{
	return VFXManager.IsValid() ? VFXManager.Get() : nullptr;
}
