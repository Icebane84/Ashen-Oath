// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 614: Ashen Three Layers Of Truth Interpreter

#include "AshenThreeLayersOfTruthInterpreter.h"

void UAshenThreeLayersOfTruthInterpreter::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenThreeLayersOfTruthInterpreter: Initialized — Three Layers Of Truth Interpreter ONLINE."));
}

void UAshenThreeLayersOfTruthInterpreter::EvaluateThreeLayersOfTruth(float IntegrationDebt, float Resolve, float Isolation)
{
	const FName L1(TEXT("Layer1.AuthoritativeRuntimeReality"));
	const FName L2 = (IntegrationDebt > 0.6f) ? FName(TEXT("Layer2.MindIsFracturing")) : FName(TEXT("Layer2.MindIsCoherent"));
	const FName L3 = (Isolation > 0.5f)       ? FName(TEXT("Layer3.HandwritingWobbleAndAudioDistortion")) : FName(TEXT("Layer3.StablePresentation"));

	OnLayersEvaluated.Broadcast(L1, L2, L3);

	UE_LOG(LogTemp, Warning, TEXT("UAshenThreeLayersOfTruthInterpreter: THREE LAYERS EVALUATED -> L1: '%s' | L2: '%s' | L3: '%s'."),
		*L1.ToString(), *L2.ToString(), *L3.ToString());
}
