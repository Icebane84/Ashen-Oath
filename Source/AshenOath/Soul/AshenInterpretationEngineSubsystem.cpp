// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 616: Ashen Interpretation Engine Subsystem (UMB-INT-001)

#include "AshenInterpretationEngineSubsystem.h"

void UAshenInterpretationEngineSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	TotalPassesExecuted = 0;
	UE_LOG(LogTemp, Log, TEXT("UAshenInterpretationEngineSubsystem: Initialized — INTERPRETATION ENGINE SUB SYSTEM ONLINE (UMB-INT-001)."));
}

void UAshenInterpretationEngineSubsystem::ExecuteInterpretationPass(FName MemoryID, EInterpretationPassType PassType)
{
	if (MemoryID.IsNone()) return;

	TotalPassesExecuted++;
	const bool bSuccess = (PassType == EInterpretationPassType::Integrative);
	OnInterpretationPassExecuted.Broadcast(MemoryID, PassType, bSuccess);

	UE_LOG(LogTemp, Warning, TEXT("UAshenInterpretationEngineSubsystem: INTERPRETATION PASS EXECUTED -> Memory '%s' | Pass: %s | Result: %s (Total: %d)."),
		*MemoryID.ToString(),
		(PassType == EInterpretationPassType::Integrative) ? TEXT("INTEGRATIVE") : TEXT("FRAGMENTATION"),
		bSuccess ? TEXT("STABILIZED") : TEXT("CONTESTED"),
		TotalPassesExecuted);
}

bool UAshenInterpretationEngineSubsystem::EvaluateInterpretiveClarity(float CurrentClarityScore, float Threshold)
{
	const bool bValid = CurrentClarityScore >= Threshold;

	UE_LOG(LogTemp, Log, TEXT("UAshenInterpretationEngineSubsystem: EVALUATE CLARITY -> Score: %.2f | Threshold: %.2f | Validated: %s."),
		CurrentClarityScore, Threshold, bValid ? TEXT("TRUE") : TEXT("FALSE"));

	return bValid;
}
