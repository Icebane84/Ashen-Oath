// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenChaosNavmeshDialogueBridge.h"

UAshenChaosNavmeshDialogueBridge::UAshenChaosNavmeshDialogueBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FText UAshenChaosNavmeshDialogueBridge::FormatChaosDestructionBark(
	EChaosFractureSeverity Severity,
	ENavmeshObstructionState Obstruction) const
{
	if (Obstruction == ENavmeshObstructionState::PulverizedCleared)
	{
		return FText::FromString(TEXT("[Garrett]: 'Clean strike! The path is open again!'"));
	}

	if (Severity == EChaosFractureSeverity::TotalDemolition || Obstruction == ENavmeshObstructionState::BlockedHighRubble)
	{
		return FText::FromString(TEXT("[Serafina]: 'The archway collapsed! The main corridor is completely blocked!'"));
	}

	if (Obstruction == ENavmeshObstructionState::VaultableLowDebris)
	{
		return FText::FromString(TEXT("[Garrett]: 'Low rubble ahead—vault over, don't slow down!'"));
	}

	return FText::FromString(TEXT("[Garrett]: 'The foundation is groaning... watch your footing!'"));
}
