// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 713: Ashen Garrett Psychological Annotation Broadcaster

#include "AshenGarrettPsychologicalAnnotationBroadcaster.h"

void UAshenGarrettPsychologicalAnnotationBroadcaster::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	TotalAnnotationsBroadcasted = 0;
	UE_LOG(LogTemp, Log, TEXT("UAshenGarrettPsychologicalAnnotationBroadcaster: Initialized — Garrett Psychological Annotation Broadcaster ONLINE."));
}

void UAshenGarrettPsychologicalAnnotationBroadcaster::BroadcastGarrettAnnotation(FText AnnotationText, FName TacticalTag)
{
	TotalAnnotationsBroadcasted++;
	OnAnnotationBroadcasted.Broadcast(AnnotationText, TacticalTag);

	UE_LOG(LogTemp, Warning, TEXT("UAshenGarrettPsychologicalAnnotationBroadcaster: GARRETT ANNOTATION BROADCASTED -> Text: '%s' | Tag: '%s' (Total: %d)."),
		*AnnotationText.ToString(), *TacticalTag.ToString(), TotalAnnotationsBroadcasted);
}
