// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenLivingCodexPostProcessAdapter.h"

UAshenLivingCodexPostProcessAdapter::UAshenLivingCodexPostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenLivingCodexPostProcessAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenLivingCodexPostProcessAdapter::SetCodexReadingVisualState(bool bIsReading, ECodexFaction Faction)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenLivingCodexPostProcessAdapter: Codex Visual State -> Reading: %s, Faction: %d"),
		bIsReading ? TEXT("TRUE") : TEXT("FALSE"), static_cast<int32>(Faction));
}
