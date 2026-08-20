// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 471: Ashen Mindscape Transition Subsystem

#include "AshenMindscapeTransitionSubsystem.h"

void UAshenMindscapeTransitionSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	CurrentDistortionIntensity = 0.0f;
	UE_LOG(LogTemp, Log, TEXT("UAshenMindscapeTransitionSubsystem: Initialized — Mindscape Transition Engine ONLINE."));
}

void UAshenMindscapeTransitionSubsystem::TransitionMindscapeState(FName MindscapeID, float DistortionIntensity)
{
	CurrentDistortionIntensity = FMath::Clamp(DistortionIntensity, 0.0f, 100.0f);
	OnMindscapeTransitioned.Broadcast(MindscapeID, CurrentDistortionIntensity);

	UE_LOG(LogTemp, Warning, TEXT("UAshenMindscapeTransitionSubsystem: MINDSCAPE TRANSITION -> '%s' (Distortion: %.1f%%)."),
		*MindscapeID.ToString(), CurrentDistortionIntensity);
}
