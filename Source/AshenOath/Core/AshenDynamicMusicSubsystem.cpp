// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 176: Ashen Dynamic Music Subsystem

#include "AshenDynamicMusicSubsystem.h"

static const TCHAR* MusicStateToString(EAshenMusicState State)
{
	switch (State)
	{
		case EAshenMusicState::Exploration:   return TEXT("Exploration");
		case EAshenMusicState::CombatLight:   return TEXT("CombatLight");
		case EAshenMusicState::CombatIntense: return TEXT("CombatIntense");
		case EAshenMusicState::BossFight:     return TEXT("BossFight");
		case EAshenMusicState::Sanctuary:     return TEXT("Sanctuary");
		case EAshenMusicState::Mindscape:     return TEXT("Mindscape");
		default:                               return TEXT("Unknown");
	}
}

void UAshenDynamicMusicSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	CurrentMusicState = EAshenMusicState::Exploration;
	UE_LOG(LogTemp, Log, TEXT("UAshenDynamicMusicSubsystem: Initialized — starting in Exploration state."));
}

void UAshenDynamicMusicSubsystem::TransitionToState(EAshenMusicState NewState)
{
	if (NewState == CurrentMusicState)
	{
		UE_LOG(LogTemp, Verbose, TEXT("UAshenDynamicMusicSubsystem: Already in state '%s' — no transition."), MusicStateToString(NewState));
		return;
	}

	const EAshenMusicState OldState = CurrentMusicState;
	CurrentMusicState = NewState;

	OnMusicStateChanged.Broadcast(OldState, NewState);

	UE_LOG(LogTemp, Warning, TEXT("UAshenDynamicMusicSubsystem: Music transition '%s' → '%s' (%.1fs crossfade)."),
		MusicStateToString(OldState), MusicStateToString(NewState), CrossfadeBlendTime);
}
