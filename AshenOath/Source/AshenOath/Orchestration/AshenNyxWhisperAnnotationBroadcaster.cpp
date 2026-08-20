// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 753: Ashen Nyx Whisper Annotation Broadcaster

#include "AshenNyxWhisperAnnotationBroadcaster.h"

void UAshenNyxWhisperAnnotationBroadcaster::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	TotalWhispersBroadcasted = 0;
	UE_LOG(LogTemp, Log, TEXT("UAshenNyxWhisperAnnotationBroadcaster: Initialized — Nyx Whisper Annotation Broadcaster ONLINE."));
}

void UAshenNyxWhisperAnnotationBroadcaster::BroadcastNyxWhisper(FText WhisperText, float TemptationLevel)
{
	TotalWhispersBroadcasted++;
	OnNyxWhisperBroadcasted.Broadcast(WhisperText, TemptationLevel);

	UE_LOG(LogTemp, Warning, TEXT("UAshenNyxWhisperAnnotationBroadcaster: NYX WHISPER BROADCASTED -> Text: '%s' | Temptation: %.1f%% (Total: %d)."),
		*WhisperText.ToString(), TemptationLevel, TotalWhispersBroadcasted);
}
