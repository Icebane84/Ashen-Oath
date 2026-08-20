// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Memory/AshenMemoryBattleSubsystem.h"

void UAshenMemoryBattleSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	bIsMemoryBattleActive = false;
	ActiveEchoID = NAME_None;
	UE_LOG(LogTemp, Log, TEXT("UAshenMemoryBattleSubsystem: Memory Battle Subsystem initialized."));
}

bool UAshenMemoryBattleSubsystem::InitiateMemoryBattle(FName EchoID, float ImprintWeight, bool bForcedCollapse)
{
	bIsMemoryBattleActive = true;
	ActiveEchoID = EchoID;

	UE_LOG(LogTemp, Warning, TEXT("UAshenMemoryBattleSubsystem: INITIATING MEMORY BATTLE for Echo '%s' (Weight: %.2f, Forced: %s)!"),
		*ActiveEchoID.ToString(), ImprintWeight, bForcedCollapse ? TEXT("TRUE") : TEXT("FALSE"));
	return true;
}

void UAshenMemoryBattleSubsystem::ConcludeMemoryBattle(bool bPlayerWon)
{
	if (!bIsMemoryBattleActive) return;

	bIsMemoryBattleActive = false;
	if (OnMemoryBattleStateChanged.IsBound())
	{
		OnMemoryBattleStateChanged.Broadcast(ActiveEchoID, bPlayerWon);
	}
	UE_LOG(LogTemp, Warning, TEXT("UAshenMemoryBattleSubsystem: Memory Battle for '%s' CONCLUDED (Victory: %s)."),
		*ActiveEchoID.ToString(), bPlayerWon ? TEXT("YES") : TEXT("NO"));
}
