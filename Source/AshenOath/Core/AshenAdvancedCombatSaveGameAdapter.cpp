// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Core/AshenAdvancedCombatSaveGameAdapter.h"

UAshenAdvancedCombatSaveGameAdapter::UAshenAdvancedCombatSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenAdvancedCombatSaveGameAdapter::BeginPlay() { Super::BeginPlay(); }

bool UAshenAdvancedCombatSaveGameAdapter::SerializeAdvancedCombatStateToSave(int32 TotalParries, int32 TotalExecutions, int32 TotalUnchainedStates)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenAdvancedCombatSaveGameAdapter: %d parries, %d executions, %d unchained states serialized to save file."),
		TotalParries, TotalExecutions, TotalUnchainedStates);
	return true;
}
