// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenOathReactivityDialogueAdapter.h"

UAshenOathReactivityDialogueAdapter::UAshenOathReactivityDialogueAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenOathReactivityDialogueAdapter::BeginPlay() { Super::BeginPlay(); }

bool UAshenOathReactivityDialogueAdapter::EvaluateDialogueNodeForOathState(FName RequiredOathID, bool bMustBeFulfilled)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenOathReactivityDialogueAdapter: Dialogue node evaluated for oath '%s' (MustBeFulfilled: %s) -> TRUE"),
		*RequiredOathID.ToString(), bMustBeFulfilled ? TEXT("YES") : TEXT("NO"));
	return true;
}
