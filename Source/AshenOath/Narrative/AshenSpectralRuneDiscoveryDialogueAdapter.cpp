// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenSpectralRuneDiscoveryDialogueAdapter.h"

UAshenSpectralRuneDiscoveryDialogueAdapter::UAshenSpectralRuneDiscoveryDialogueAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenSpectralRuneDiscoveryDialogueAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenSpectralRuneDiscoveryDialogueAdapter::TriggerRuneDiscoveryDialogue(FName RuneTag)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenSpectralRuneDiscoveryDialogueAdapter: Dialogue triggered for Rune '%s' ('Look, Kaelen! An ancient sigil illuminated by the oil!')"), *RuneTag.ToString());
}
