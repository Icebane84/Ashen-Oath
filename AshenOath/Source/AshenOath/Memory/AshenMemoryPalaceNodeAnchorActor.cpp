// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Memory/AshenMemoryPalaceNodeAnchorActor.h"
#include "Memory/AshenMemoryPalaceGraphSubsystem.h"
#include "Memory/AshenMemoryBattleSubsystem.h"
#include "Combat/AshenCombatCharacter.h"
#include "Combat/AshenOath_SanityComponent.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"

AAshenMemoryPalaceNodeAnchorActor::AAshenMemoryPalaceNodeAnchorActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsAnchored = false;
	AnchoredMemoryID = FName(TEXT("Memory.NodeDefault"));
	NodeType = EMemoryNodeType::EchoLocus;
	TraumaLevel = EMemoryTraumaLevel::Dormant;
	ResonancePower = 100.0f;
}

void AAshenMemoryPalaceNodeAnchorActor::AnchorMemoryNode(FName MemoryID, float InResonancePower)
{
	AnchoredMemoryID = MemoryID;
	ResonancePower = InResonancePower;
	bIsAnchored = true;
	OnMemoryNodeAnchored.Broadcast(AnchoredMemoryID, ResonancePower);

	UE_LOG(LogTemp, Warning, TEXT("AAshenMemoryPalaceNodeAnchorActor: MEMORY NODE ANCHORED -> Memory '%s' | Resonance: %.0f."),
		*AnchoredMemoryID.ToString(), ResonancePower);
}

bool AAshenMemoryPalaceNodeAnchorActor::InteractWithAnchor(AAshenCombatCharacter* Interactor)
{
	if (AnchoredMemoryID.IsNone())
	{
		UE_LOG(LogTemp, Warning, TEXT("AAshenMemoryPalaceNodeAnchorActor::InteractWithAnchor - AnchoredMemoryID is None."));
		return false;
	}

	UWorld* World = GetWorld();
	if (!World)
	{
		return false;
	}

	// 1. Ensure node is registered in Memory Palace Graph
	if (UGameInstance* GI = World->GetGameInstance())
	{
		if (UAshenMemoryPalaceGraphSubsystem* GraphSubsystem = GI->GetSubsystem<UAshenMemoryPalaceGraphSubsystem>())
		{
			FMemoryGraphNode ExistingNode;
			if (!GraphSubsystem->GetNode(AnchoredMemoryID, ExistingNode))
			{
				FMemoryGraphNode NewNode;
				NewNode.NodeID = AnchoredMemoryID;
				NewNode.NodeType = NodeType;
				NewNode.TraumaLevel = TraumaLevel;
				NewNode.WorldPosition = GetActorLocation();
				NewNode.bIsUnsealed = false;
				NewNode.bIsReconstructed = false;
				GraphSubsystem->RegisterNode(NewNode);
			}
		}
	}

	// 2. Branch on Trauma Level
	if (TraumaLevel == EMemoryTraumaLevel::Dormant)
	{
		// Peaceful / Dormant memory: Unseal immediately and restore baseline sanity
		if (UGameInstance* GI = World->GetGameInstance())
		{
			if (UAshenMemoryPalaceGraphSubsystem* GraphSubsystem = GI->GetSubsystem<UAshenMemoryPalaceGraphSubsystem>())
			{
				GraphSubsystem->UnsealNode(AnchoredMemoryID);
			}
		}

		if (Interactor)
		{
			if (UAshenOath_SanityComponent* Sanity = Interactor->FindComponentByClass<UAshenOath_SanityComponent>())
			{
				Sanity->HealSanity(10.0f);
			}
		}

		bIsAnchored = true;
		OnMemoryNodeAnchored.Broadcast(AnchoredMemoryID, ResonancePower);
		OnMemoryNodeInteracted.Broadcast(AnchoredMemoryID, TraumaLevel, false);

		UE_LOG(LogTemp, Log, TEXT("AAshenMemoryPalaceNodeAnchorActor: Dormant memory '%s' unsealed successfully."),
			*AnchoredMemoryID.ToString());
		return true;
	}
	else
	{
		// Traumatic / Contested memory: Initiate Memory Battle
		if (UAshenMemoryBattleSubsystem* BattleSubsystem = World->GetSubsystem<UAshenMemoryBattleSubsystem>())
		{
			const bool bBattleStarted = BattleSubsystem->InitiateMemoryBattle(AnchoredMemoryID, ResonancePower, false);
			OnMemoryNodeInteracted.Broadcast(AnchoredMemoryID, TraumaLevel, bBattleStarted);

			UE_LOG(LogTemp, Warning, TEXT("AAshenMemoryPalaceNodeAnchorActor: Traumatic memory '%s' triggered Memory Battle!"),
				*AnchoredMemoryID.ToString());
			return bBattleStarted;
		}
	}

	return false;
}
