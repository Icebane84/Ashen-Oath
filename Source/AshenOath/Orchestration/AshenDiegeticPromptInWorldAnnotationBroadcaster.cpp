// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 829: Ashen Diegetic Prompt In-World Annotation Broadcaster

#include "AshenDiegeticPromptInWorldAnnotationBroadcaster.h"

void UAshenDiegeticPromptInWorldAnnotationBroadcaster::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	TotalPromptAnnotationsBroadcasted = 0;
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticPromptInWorldAnnotationBroadcaster: Initialized — Diegetic Prompt Annotation Broadcaster ONLINE."));
}

void UAshenDiegeticPromptInWorldAnnotationBroadcaster::BroadcastPromptAnnotation(FText AnnotationText, FName StateTag)
{
	TotalPromptAnnotationsBroadcasted++;
	OnPromptAnnotationBroadcasted.Broadcast(AnnotationText, StateTag);

	UE_LOG(LogTemp, Warning, TEXT("UAshenDiegeticPromptInWorldAnnotationBroadcaster: DIEGETIC PROMPT ANNOTATION BROADCASTED -> Text: '%s' | Tag: '%s' (Total: %d)."),
		*AnnotationText.ToString(), *StateTag.ToString(), TotalPromptAnnotationsBroadcasted);
}
