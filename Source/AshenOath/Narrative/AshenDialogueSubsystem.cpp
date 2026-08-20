// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 544: Ashen Dialogue Subsystem

#include "AshenDialogueSubsystem.h"

void UAshenDialogueSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	bBarksMuted = false;
	UE_LOG(LogTemp, Log, TEXT("UAshenDialogueSubsystem: Initialized — Dialogue & Bark Subsystem ONLINE."));
}

bool UAshenDialogueSubsystem::TriggerDialogueLine(FName SpeakerID, FString DialogueText, bool bIsBark)
{
	if (bIsBark && bBarksMuted)
	{
		UE_LOG(LogTemp, Log, TEXT("UAshenDialogueSubsystem: Bark muted during Peak Resonance lethal silence."));
		return false;
	}

	OnDialogueLineTriggered.Broadcast(SpeakerID, DialogueText);

	UE_LOG(LogTemp, Warning, TEXT("UAshenDialogueSubsystem: DIALOGUE TRIGGERED [%s]: \"%s\""),
		*SpeakerID.ToString(), *DialogueText);

	return true;
}
