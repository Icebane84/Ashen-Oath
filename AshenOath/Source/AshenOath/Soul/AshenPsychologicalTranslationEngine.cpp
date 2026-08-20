// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 608: Ashen Psychological Translation Engine

#include "AshenPsychologicalTranslationEngine.h"

void UAshenPsychologicalTranslationEngine::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenPsychologicalTranslationEngine: Initialized — Psychological Translation Engine ONLINE."));
}

void UAshenPsychologicalTranslationEngine::TranslateEngineVariables(float IntegrationDebt, float Resolve, float GarrettTrust)
{
	// Translate Layer I into Layer II human psychological language
	CurrentMindStateText = (IntegrationDebt > 0.7f) ? TEXT("Mind is Fracturing") : TEXT("Mind is Coherent");
	CurrentResolveText   = (Resolve > 0.6f) ? TEXT("Resolve is Determined") : TEXT("Resolve is Wavering");
	CurrentGarrettBehaviorText = (GarrettTrust > 0.8f) ? TEXT("Garrett Trusting & Watchful") : TEXT("Garrett Concerned & Distant");

	OnTranslationExecuted.Broadcast(CurrentMindStateText, CurrentResolveText, CurrentGarrettBehaviorText);

	UE_LOG(LogTemp, Warning, TEXT("UAshenPsychologicalTranslationEngine: TRANSLATED LAYER I -> [%s] | [%s] | [%s]."),
		*CurrentMindStateText, *CurrentResolveText, *CurrentGarrettBehaviorText);
}
