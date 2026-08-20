// Copyright Phoenix Protocol. All rights reserved.

#include "AshenOath_LootComponent.h"
#include "AshenLootDropActor.h"
#include "AshenOath_DirectorSubsystem.h"
#include "AshenCharacterInterface.h"
#include "AshenOath_StatsComponent.h"
#include "Components/BoxComponent.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Pawn.h"

UAshenOath_LootComponent::UAshenOath_LootComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	XpValue = 25;
	DropChance = 0.5f;
	LootDropClass = AAshenLootDropActor::StaticClass();
}

void UAshenOath_LootComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenOath_LootComponent::SpawnLoot()
{
	if (!GetWorld() || !GetWorld()->GetGameInstance()) return;

	UAshenOath_DirectorSubsystem* Director = GetWorld()->GetGameInstance()->GetSubsystem<UAshenOath_DirectorSubsystem>();
	if (!Director) return;

	APawn* PlayerPawn = Director->GetPlayerPawn();

	// 1. Award XP to Kaelen (Player)
	if (PlayerPawn && PlayerPawn->Implements<UAshenCharacterInterface>())
	{
		if (UAshenOath_StatsComponent* Stats = IAshenCharacterInterface::Execute_GetStatsComponent(PlayerPawn))
		{
			Stats->AddXp(XpValue);
		}
	}

	// 2. Physical Drop Logic check
	if (FMath::FRand() <= DropChance && LootTable.Num() > 0 && LootDropClass)
	{
		int32 RandomIndex = FMath::RandRange(0, LootTable.Num() - 1);
		FAshenItemData SelectedItem = LootTable[RandomIndex];

		FVector SpawnLocation = GetOwner()->GetActorLocation() + FVector(0.0f, 0.0f, 50.0f);

		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		AAshenLootDropActor* SpawnedLoot = GetWorld()->SpawnActor<AAshenLootDropActor>(
			LootDropClass,
			SpawnLocation,
			FRotator::ZeroRotator,
			SpawnParams
		);

		if (SpawnedLoot)
		{
			SpawnedLoot->LootItem = SelectedItem;

			// Apply physical pop-out impulse on box collision root component
			if (UBoxComponent* Box = Cast<UBoxComponent>(SpawnedLoot->GetRootComponent()))
			{
				FVector PushImpulse = FVector(
					FMath::FRandRange(-150.0f, 150.0f),
					FMath::FRandRange(-150.0f, 150.0f),
					FMath::FRandRange(400.0f, 600.0f)
				);
				Box->AddImpulse(PushImpulse, NAME_None, true);
			}
		}
	}
}
