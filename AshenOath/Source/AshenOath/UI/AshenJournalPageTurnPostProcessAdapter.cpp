// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenJournalPageTurnPostProcessAdapter.h"

UAshenJournalPageTurnPostProcessAdapter::UAshenJournalPageTurnPostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = true;
	CurrentFocus = 0.0f;
	TargetFocus = 0.0f;
}

void UAshenJournalPageTurnPostProcessAdapter::TickComponent(
	float DeltaTime,
	ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	CurrentFocus = FMath::FInterpTo(CurrentFocus, TargetFocus, DeltaTime, 4.0f);
}

void UAshenJournalPageTurnPostProcessAdapter::SetJournalFocus(bool bInFocus)
{
	TargetFocus = bInFocus ? 1.0f : 0.0f;
}
