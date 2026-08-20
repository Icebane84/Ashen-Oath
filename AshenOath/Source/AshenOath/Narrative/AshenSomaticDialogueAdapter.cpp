// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenSomaticDialogueAdapter.h"
#include "Engine/World.h"
#include "Orchestration/AshenUniversalSomaticEngineSubsystem.h"

UAshenSomaticDialogueAdapter::UAshenSomaticDialogueAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	MechanicalLockoutThreshold = 0.85f;
}

FActionCongruenceResult UAshenSomaticDialogueAdapter::PrepareDialogueBranch(
	const FCanonicalSoulStateVector& SoulState,
	const FCanonicalRelationalMatrix& RelationalState,
	FGameplayTag ChoiceTag,
	EOntologicalLens ChoiceLens,
	float MemorySeverity,
	FName CompanionTargetName)
{
	FActionCongruenceResult Result;
	Result.IntendedActionTag = ChoiceTag;
	Result.MemorySeverity = MemorySeverity;

	if (UWorld* World = GetWorld())
	{
		if (UAshenUniversalSomaticEngineSubsystem* SomaticSub = World->GetSubsystem<UAshenUniversalSomaticEngineSubsystem>())
		{
			Result = SomaticSub->EvaluateActionCongruence(
				SoulState,
				RelationalState,
				ChoiceTag,
				ChoiceLens,
				MemorySeverity,
				CompanionTargetName,
				FGuid::NewGuid(),
				SoulState.StateVersion);
		}
	}

	LastBranchResult = Result;
	return Result;
}

bool UAshenSomaticDialogueAdapter::RequiresMechanicalLockout(float ResistanceSomatic) const
{
	return ResistanceSomatic >= MechanicalLockoutThreshold;
}
