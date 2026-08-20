// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenJournalCharcoalStrikethroughComponent.h"

UAshenJournalCharcoalStrikethroughComponent::UAshenJournalCharcoalStrikethroughComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenJournalCharcoalStrikethroughComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenJournalCharcoalStrikethroughComponent::ApplyCharcoalStrikethrough(bool bEnableStrikethrough)
{
	bStrikethroughVisible = bEnableStrikethrough;
	UE_LOG(LogTemp, Log, TEXT("UAshenJournalCharcoalStrikethroughComponent: Charcoal strikethrough set to %s"),
		bStrikethroughVisible ? TEXT("VISIBLE ('~~I am their shield.~~')") : TEXT("HIDDEN"));
}
