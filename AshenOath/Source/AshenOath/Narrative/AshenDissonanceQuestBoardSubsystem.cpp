// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenDissonanceQuestBoardSubsystem.h"

UAshenDissonanceQuestBoardSubsystem::UAshenDissonanceQuestBoardSubsystem()
{
}

void UAshenDissonanceQuestBoardSubsystem::RegisterQuestContract(
	const FDissonanceQuestContract& Contract)
{
	ActiveContracts.Add(Contract);
	OnDissonanceQuestGenerated.Broadcast(Contract);
}

bool UAshenDissonanceQuestBoardSubsystem::ResolveContract(
	FName ContractId,
	EQuestResolutionOutcome Outcome)
{
	for (int32 i = 0; i < ActiveContracts.Num(); ++i)
	{
		if (ActiveContracts[i].ContractId == ContractId)
		{
			FDissonanceQuestContract Resolved = ActiveContracts[i];
			Resolved.Outcome = Outcome;
			Resolved.bIsCompleted = true;

			ActiveContracts.RemoveAt(i);
			ResolvedContracts.Add(Resolved);

			OnDissonanceQuestResolved.Broadcast(ContractId, Outcome);
			return true;
		}
	}
	return false;
}
