// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 773: Ashen Act 01 Dialogue Annotation Broadcaster

#include "AshenAct01DialogueAnnotationBroadcaster.h"

void UAshenAct01DialogueAnnotationBroadcaster::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	TotalSubtitlesBroadcasted = 0;
	UE_LOG(LogTemp, Log, TEXT("UAshenAct01DialogueAnnotationBroadcaster: Initialized — Act 01 Dialogue Annotation Broadcaster ONLINE."));
}

void UAshenAct01DialogueAnnotationBroadcaster::BroadcastCinematicSubtitle(FName SpeakerName, FText DialogueLine)
{
	TotalSubtitlesBroadcasted++;
	OnSubtitleBroadcasted.Broadcast(SpeakerName, DialogueLine);

	UE_LOG(LogTemp, Warning, TEXT("UAshenAct01DialogueAnnotationBroadcaster: SUBTITLE BROADCASTED -> Speaker: '%s' | Line: '%s' (Total: %d)."),
		*SpeakerName.ToString(), *DialogueLine.ToString(), TotalSubtitlesBroadcasted);
}
