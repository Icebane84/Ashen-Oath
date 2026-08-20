// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Core/AshenBestiaryFinisherSaveGameAdapter.h"

UAshenBestiaryFinisherSaveGameAdapter::UAshenBestiaryFinisherSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenBestiaryFinisherSaveGameAdapter::BeginPlay() { Super::BeginPlay(); }

bool UAshenBestiaryFinisherSaveGameAdapter::SerializeBestiaryFinisherToSave(EAshenPartyFinisherType FinisherType, bool bLoreUnlocked)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenBestiaryFinisherSaveGameAdapter: Bestiary Finisher Type %d (Lore: %s) serialized to save game."),
		(int32)FinisherType, bLoreUnlocked ? TEXT("UNLOCKED") : TEXT("LOCKED"));
	return true;
}
