// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Memory/AshenMemoryBattleComponent.h"

UAshenMemoryBattleComponent::UAshenMemoryBattleComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenMemoryBattleComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenMemoryBattleComponent::InitiateMemoryBattle(FAshenMemoryBattleDefinition BattleDef)
{
	bMemoryBattleActive = true;
	UE_LOG(LogTemp, Warning, TEXT("UAshenMemoryBattleComponent: Initiated Memory Battle for %s"), *BattleDef.MemoryID.ToString());
}

void UAshenMemoryBattleComponent::ResolveMemoryBattle(FName MemoryID, bool bVictory)
{
	bMemoryBattleActive = false;
	EAshenMemoryBattleOutcome Outcome = bVictory ? EAshenMemoryBattleOutcome::VictoryIntegrated : EAshenMemoryBattleOutcome::DefeatShadowCorruption;
	if (OnMemoryBattleCompleted.IsBound())
	{
		OnMemoryBattleCompleted.Broadcast(MemoryID, Outcome);
	}
	UE_LOG(LogTemp, Warning, TEXT("UAshenMemoryBattleComponent: Resolved Memory Battle for %s (Victory: %s)"), *MemoryID.ToString(), bVictory ? TEXT("True") : TEXT("False"));
}
