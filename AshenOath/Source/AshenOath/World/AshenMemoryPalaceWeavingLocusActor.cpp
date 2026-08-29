// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenMemoryPalaceWeavingLocusActor.h"
#include "Memory/AshenMemoryPalaceGraphSubsystem.h"
#include "Combat/AshenOath_SanityComponent.h"
#include "Combat/AshenCombatCharacter.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"

AAshenMemoryPalaceWeavingLocusActor::AAshenMemoryPalaceWeavingLocusActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsWeaved = false;
	BoundMemoryNodeTag = FName(TEXT("can-grace_vs_accountability"));
}

void AAshenMemoryPalaceWeavingLocusActor::ExecuteMemoryWeavingPass(bool bSelectGraceLens, AActor* Interactor)
{
	if (bIsWeaved)
	{
		return;
	}

	bIsWeaved = true;
	UWorld* World = GetWorld();

	// 1. Unseal the memory node in the Palace Graph Subsystem
	if (World)
	{
		if (UGameInstance* GI = World->GetGameInstance())
		{
			if (UAshenMemoryPalaceGraphSubsystem* GraphSubsystem = GI->GetSubsystem<UAshenMemoryPalaceGraphSubsystem>())
			{
				GraphSubsystem->UnsealNode(BoundMemoryNodeTag);
			}
		}
	}

	// 2. Heal Interactor Sanity (+20.0)
	if (Interactor)
	{
		if (UAshenOath_SanityComponent* SanityComp = Interactor->FindComponentByClass<UAshenOath_SanityComponent>())
		{
			SanityComp->HealSanity(20.0f);
		}

		if (AAshenCombatCharacter* CombatChar = Cast<AAshenCombatCharacter>(Interactor))
		{
			CombatChar->HandleRunicSeamColorUpdated(FLinearColor(1.0f, 0.85f, 0.4f, 1.0f), 3.0f);
		}
	}

	OnWeavingLocusActivated.Broadcast(BoundMemoryNodeTag, bSelectGraceLens);

	UE_LOG(LogTemp, Warning, TEXT("AAshenMemoryPalaceWeavingLocusActor: Memory Node [%s] successfully weaved! (Grace: %s | +20 Sanity)."),
		*BoundMemoryNodeTag.ToString(), bSelectGraceLens ? TEXT("TRUE") : TEXT("FALSE"));
}
