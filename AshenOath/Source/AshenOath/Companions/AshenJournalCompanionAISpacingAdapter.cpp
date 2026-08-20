// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Companions/AshenJournalCompanionAISpacingAdapter.h"

UAshenJournalCompanionAISpacingAdapter::UAshenJournalCompanionAISpacingAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenJournalCompanionAISpacingAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenJournalCompanionAISpacingAdapter::UpdateCompanionSpacingForFriction(bool bGuardedFriction)
{
	if (bGuardedFriction)
	{
		CompanionFollowDistance = 700.0f;
		bHandOnPommelStance = true;
	}
	else
	{
		CompanionFollowDistance = 300.0f;
		bHandOnPommelStance = false;
	}

	UE_LOG(LogTemp, Log, TEXT("UAshenJournalCompanionAISpacingAdapter: Companion Follow Distance set to %.0fuu | HandOnPommel: %s"),
		CompanionFollowDistance, bHandOnPommelStance ? TEXT("TRUE") : TEXT("FALSE"));
}
