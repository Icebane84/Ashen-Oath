// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 271: Ashen Dungeon Loot Keycard Component

#include "AshenDungeonLootKeycardComponent.h"

UAshenDungeonLootKeycardComponent::UAshenDungeonLootKeycardComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	KeycardID = FName("RuneKey_GreywatchGate");
	bIsCollected = false;
}

void UAshenDungeonLootKeycardComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenDungeonLootKeycardComponent::CollectKeycard(AActor* CollectingActor)
{
	if (bIsCollected) return;

	bIsCollected = true;
	OnKeycardCollected.Broadcast(KeycardID);

	UE_LOG(LogTemp, Warning, TEXT("UAshenDungeonLootKeycardComponent: RUNE KEYCARD '%s' COLLECTED by '%s'."),
		*KeycardID.ToString(), CollectingActor ? *CollectingActor->GetName() : TEXT("Unknown"));
}
