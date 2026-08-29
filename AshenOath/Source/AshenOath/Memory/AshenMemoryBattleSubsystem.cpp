// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Memory/AshenMemoryBattleSubsystem.h"
#include "Memory/AshenMemoryPalaceGraphSubsystem.h"
#include "Memory/AshenIntegrationDebtAccumulatorSubsystem.h"
#include "Companions/AshenDevilsBargainTrustAtrophyDirector.h"
#include "Combat/AshenCombatCharacter.h"
#include "Combat/AshenOath_SanityComponent.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"
#include "Kismet/GameplayStatics.h"

void UAshenMemoryBattleSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	bIsMemoryBattleActive = false;
	ActiveEchoID = NAME_None;
	ActiveEchoWeight = 0.0f;
	UE_LOG(LogTemp, Log, TEXT("UAshenMemoryBattleSubsystem: Memory Battle Subsystem initialized."));
}

bool UAshenMemoryBattleSubsystem::InitiateMemoryBattle(FName EchoID, float ImprintWeight, bool bForcedCollapse)
{
	bIsMemoryBattleActive = true;
	ActiveEchoID = EchoID;
	ActiveEchoWeight = ImprintWeight;

	UE_LOG(LogTemp, Warning, TEXT("UAshenMemoryBattleSubsystem: INITIATING MEMORY BATTLE for Echo '%s' (Weight: %.2f, Forced: %s)!"),
		*ActiveEchoID.ToString(), ImprintWeight, bForcedCollapse ? TEXT("TRUE") : TEXT("FALSE"));
	return true;
}

void UAshenMemoryBattleSubsystem::ConcludeMemoryBattle(bool bPlayerWon)
{
	AAshenCombatCharacter* PlayerChar = nullptr;
	if (UWorld* World = GetWorld())
	{
		PlayerChar = Cast<AAshenCombatCharacter>(UGameplayStatics::GetPlayerCharacter(World, 0));
	}
	ConcludeMemoryBattleForCharacter(bPlayerWon, PlayerChar);
}

void UAshenMemoryBattleSubsystem::ConcludeMemoryBattleForCharacter(bool bPlayerWon, AAshenCombatCharacter* TargetChar)
{
	if (!bIsMemoryBattleActive)
	{
		return;
	}

	bIsMemoryBattleActive = false;
	UWorld* World = GetWorld();

	if (bPlayerWon)
	{
		// 1. Unseal node in Memory Palace Graph Subsystem
		if (World)
		{
			if (UGameInstance* GI = World->GetGameInstance())
			{
				if (UAshenMemoryPalaceGraphSubsystem* GraphSubsystem = GI->GetSubsystem<UAshenMemoryPalaceGraphSubsystem>())
				{
					GraphSubsystem->UnsealNode(ActiveEchoID);
				}
			}
		}

		// 2. Heal Kaelen's Sanity by +25.0
		if (TargetChar)
		{
			if (UAshenOath_SanityComponent* Sanity = TargetChar->FindComponentByClass<UAshenOath_SanityComponent>())
			{
				Sanity->HealSanity(25.0f);
			}
		}

		// 3. Grant +5% Companion Trust for facing trauma together
		if (World)
		{
			if (UGameInstance* GI = World->GetGameInstance())
			{
				if (UAshenDevilsBargainTrustAtrophyDirector* TrustDirector = GI->GetSubsystem<UAshenDevilsBargainTrustAtrophyDirector>())
				{
					TrustDirector->RestoreTrust(5.0f);
				}
			}
		}

		UE_LOG(LogTemp, Warning, TEXT("UAshenMemoryBattleSubsystem: Memory Battle for '%s' CONCLUDED IN VICTORY! (+25.0 Sanity, +5%% Trust, Graph Node Unsealed)."),
			*ActiveEchoID.ToString());
	}
	else
	{
		// 1. Defeat Consequence: Suffer -30.0 Mental Damage to Sanity
		if (TargetChar)
		{
			if (UAshenOath_SanityComponent* Sanity = TargetChar->FindComponentByClass<UAshenOath_SanityComponent>())
			{
				Sanity->SufferMentalDamage(30.0f);
			}
		}

		// 2. Accumulate +20% Integration Debt pressure
		if (World)
		{
			if (UAshenIntegrationDebtAccumulatorSubsystem* DebtSubsystem = World->GetSubsystem<UAshenIntegrationDebtAccumulatorSubsystem>())
			{
				DebtSubsystem->AccumulateDebt(0.20f);
			}
		}

		UE_LOG(LogTemp, Warning, TEXT("UAshenMemoryBattleSubsystem: Memory Battle for '%s' CONCLUDED IN DEFEAT! (-30.0 Sanity, +20%% Integration Debt)."),
			*ActiveEchoID.ToString());
	}

	if (OnMemoryBattleStateChanged.IsBound())
	{
		OnMemoryBattleStateChanged.Broadcast(ActiveEchoID, bPlayerWon);
	}
}
