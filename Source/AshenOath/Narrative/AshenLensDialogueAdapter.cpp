// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenLensDialogueAdapter.h"

UAshenLensDialogueAdapter::UAshenLensDialogueAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenLensDialogueAdapter::BeginPlay() { Super::BeginPlay(); }

bool UAshenLensDialogueAdapter::IsDialogueChoiceUnlocked(FName ChoiceID, EInterpretiveLens Lens)
{
	bool bUnlocked = true;
	if (ChoiceID == FName(TEXT("Choice.ForgiveMalakor")) && Lens == EInterpretiveLens::Accountability)
	{
		bUnlocked = false; // Accountability demands justice/consequences
	}

	UE_LOG(LogTemp, Log, TEXT("UAshenLensDialogueAdapter: Dialogue Choice '%s' evaluated (Unlocked: %s) under Lens %d."),
		*ChoiceID.ToString(), bUnlocked ? TEXT("TRUE") : TEXT("FALSE"), static_cast<int32>(Lens));
	return bUnlocked;
}
