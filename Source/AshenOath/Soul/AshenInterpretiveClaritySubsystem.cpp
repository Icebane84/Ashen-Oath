// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 619: Ashen Interpretive Clarity Subsystem

#include "AshenInterpretiveClaritySubsystem.h"

void UAshenInterpretiveClaritySubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	ActiveClarityScore = 0.85f;
	UE_LOG(LogTemp, Log, TEXT("UAshenInterpretiveClaritySubsystem: Initialized — Interpretive Clarity Subsystem ONLINE."));
}

bool UAshenInterpretiveClaritySubsystem::EvaluateClarityAgainstWhisper(float WhisperErosionIntensity)
{
	const bool bResisted = ActiveClarityScore >= (WhisperErosionIntensity / 100.0f);
	OnClarityEvaluated.Broadcast(ActiveClarityScore, bResisted);

	UE_LOG(LogTemp, Warning, TEXT("UAshenInterpretiveClaritySubsystem: EVALUATED CLARITY -> Score: %.2f | Whisper Intensity: %.1f | Resisted: %s."),
		ActiveClarityScore, WhisperErosionIntensity, bResisted ? TEXT("TRUE") : TEXT("FALSE"));

	return bResisted;
}
