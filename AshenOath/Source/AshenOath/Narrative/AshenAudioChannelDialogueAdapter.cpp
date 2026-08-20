// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenAudioChannelDialogueAdapter.h"

UAshenAudioChannelDialogueAdapter::UAshenAudioChannelDialogueAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenAudioChannelDialogueAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenAudioChannelDialogueAdapter::TriggerChannelDialogue(FName SpeakerID, const FString& Line, EAudioConsciousnessChannel Channel)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenAudioChannelDialogueAdapter: Dialogue [%s | Channel %d]: \"%s\""),
		*SpeakerID.ToString(), static_cast<int32>(Channel), *Line);
}
