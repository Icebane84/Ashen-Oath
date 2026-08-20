// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 361: Ashen Cognitive AI Behavior Subsystem

#include "AshenCognitiveAIBehaviorSubsystem.h"

void UAshenCognitiveAIBehaviorSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenCognitiveAIBehaviorSubsystem: Initialized — Cognitive AI Subsystem active."));
}

void UAshenCognitiveAIBehaviorSubsystem::ModulateAIBasedOnSanity(float CurrentSanity)
{
	const float AggressivenessMult = (CurrentSanity < 30.0f) ? 1.75f : 1.0f;
	OnAIAggressivenessModulated.Broadcast(CurrentSanity, AggressivenessMult);

	UE_LOG(LogTemp, Warning, TEXT("UAshenCognitiveAIBehaviorSubsystem: COGNITIVE AI MODULATED (Sanity: %.1f) -> AI Aggressiveness Multiplier: %.2fx."),
		CurrentSanity, AggressivenessMult);
}
