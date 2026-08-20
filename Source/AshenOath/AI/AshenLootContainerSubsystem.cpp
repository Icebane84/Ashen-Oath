// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenLootContainerSubsystem.h"
#include "AshenLootDropActor.h"

void UAshenLootContainerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	OpenedContainerIDs.Empty();
	UE_LOG(LogTemp, Warning, TEXT("UAshenLootContainerSubsystem: Interactive chest container subsystem initialized."));
}

void UAshenLootContainerSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

void UAshenLootContainerSubsystem::RegisterContainerOpened(FName ContainerID)
{
	if (ContainerID == NAME_None) return;

	OpenedContainerIDs.Add(ContainerID);
	OnContainerStateChanged.Broadcast(ContainerID, true);
	UE_LOG(LogTemp, Warning, TEXT("UAshenLootContainerSubsystem: Container '%s' registered as OPENED."), *ContainerID.ToString());
}

bool UAshenLootContainerSubsystem::IsContainerOpened(FName ContainerID) const
{
	return OpenedContainerIDs.Contains(ContainerID);
}

void UAshenLootContainerSubsystem::GenerateLootDrop(FName ContainerID, FVector DropLocation)
{
	if (IsContainerOpened(ContainerID)) return;

	RegisterContainerOpened(ContainerID);

	if (GetWorld())
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		AAshenLootDropActor* LootDrop = GetWorld()->SpawnActor<AAshenLootDropActor>(AAshenLootDropActor::StaticClass(), DropLocation, FRotator::ZeroRotator, SpawnParams);
		if (LootDrop)
		{
			UE_LOG(LogTemp, Warning, TEXT("UAshenLootContainerSubsystem: Spawned loot drop at location for container '%s'."), *ContainerID.ToString());
		}
	}
}
