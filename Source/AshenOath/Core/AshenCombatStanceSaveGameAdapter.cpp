// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Core/AshenCombatStanceSaveGameAdapter.h"

UAshenCombatStanceSaveGameAdapter::UAshenCombatStanceSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenCombatStanceSaveGameAdapter::BeginPlay() { Super::BeginPlay(); }

bool UAshenCombatStanceSaveGameAdapter::SaveCombatStanceMastery(ECombatStance Stance, int32 MasteryLevel, int32 FlankExecutions)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenCombatStanceSaveGameAdapter: Saved Combat Stance Mastery (Stance: %d, Level: %d, Flank Executions: %d) to SaveGame."),
		static_cast<int32>(Stance), MasteryLevel, FlankExecutions);
	return true;
}
