// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Narrative/AshenFieldJournalPageController.h"

UAshenFieldJournalPageController::UAshenFieldJournalPageController()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenFieldJournalPageController::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenFieldJournalPageController::FlipPageForward()
{
	CurrentPageIndex++;
	UE_LOG(LogTemp, Log, TEXT("UAshenFieldJournalPageController: Flipped journal page forward to %d"), CurrentPageIndex);
}

void UAshenFieldJournalPageController::FlipPageBackward()
{
	CurrentPageIndex = FMath::Max(1, CurrentPageIndex - 1);
	UE_LOG(LogTemp, Log, TEXT("UAshenFieldJournalPageController: Flipped journal page backward to %d"), CurrentPageIndex);
}
