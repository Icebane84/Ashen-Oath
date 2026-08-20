// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenMemoryWeavingDialogueAdapter.h"

UAshenMemoryWeavingDialogueAdapter::UAshenMemoryWeavingDialogueAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenMemoryWeavingDialogueAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenMemoryWeavingDialogueAdapter::TriggerWeavingBark(EWeavingPatternType Pattern, bool bDidSnap)
{
	if (bDidSnap)
	{
		UE_LOG(LogTemp, Error, TEXT("UAshenMemoryWeavingDialogueAdapter: Serafina: \"The thread gave out! Brace yourself!\""));
		return;
	}

	switch (Pattern)
	{
	case EWeavingPatternType::AegisNet:
		UE_LOG(LogTemp, Warning, TEXT("UAshenMemoryWeavingDialogueAdapter: Serafina: \"Hold the line, Kaelen! I have you woven!\""));
		break;
	case EWeavingPatternType::TraumaBridge:
		UE_LOG(LogTemp, Warning, TEXT("UAshenMemoryWeavingDialogueAdapter: Serafina: \"The memory holds. Cross quickly!\""));
		break;
	case EWeavingPatternType::ResonanceChord:
		UE_LOG(LogTemp, Log, TEXT("UAshenMemoryWeavingDialogueAdapter: Garrett: \"The chime is clean. Strike now!\""));
		break;
	}
}
