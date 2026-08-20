// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenRICSandboxStateVectorDiffEngine.h"

void UAshenRICSandboxStateVectorDiffEngine::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenRICSandboxStateVectorDiffEngine: State Vector Diff Engine initialized."));
}

float UAshenRICSandboxStateVectorDiffEngine::CalculateStateDelta(float VolatileWeight, float CompiledState)
{
	float Delta = FMath::Clamp(VolatileWeight - CompiledState, -0.20f, 0.20f);
	UE_LOG(LogTemp, Log, TEXT("UAshenRICSandboxStateVectorDiffEngine: Calculated state delta -> %.4f"), Delta);
	return Delta;
}
