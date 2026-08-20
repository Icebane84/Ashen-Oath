// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 733: Ashen Serafina Empathic Annotation Broadcaster

#include "AshenSerafinaEmpathicAnnotationBroadcaster.h"

void UAshenSerafinaEmpathicAnnotationBroadcaster::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	TotalAnnotationsBroadcasted = 0;
	UE_LOG(LogTemp, Log, TEXT("UAshenSerafinaEmpathicAnnotationBroadcaster: Initialized — Serafina Empathic Annotation Broadcaster ONLINE."));
}

void UAshenSerafinaEmpathicAnnotationBroadcaster::BroadcastSerafinaAnnotation(FText AnnotationText, FName EmpathicTag)
{
	TotalAnnotationsBroadcasted++;
	OnAnnotationBroadcasted.Broadcast(AnnotationText, EmpathicTag);

	UE_LOG(LogTemp, Warning, TEXT("UAshenSerafinaEmpathicAnnotationBroadcaster: SERAFINA ANNOTATION BROADCASTED -> Text: '%s' | Tag: '%s' (Total: %d)."),
		*AnnotationText.ToString(), *EmpathicTag.ToString(), TotalAnnotationsBroadcasted);
}
