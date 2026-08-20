// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 688: Ashen Garrett Flank EQS Evaluator

#include "AshenGarrettFlankEQSEvaluator.h"

FVector UAshenGarrettFlankEQSEvaluator::EvaluateGarrettBlindSpotPosition(FVector KaelenLocation, FVector KaelenForwardVector, bool bIsKaelenUnbroken)
{
	const FVector BlindSpotOffset = -KaelenForwardVector.GetSafeNormal() * 300.0f; // Directly behind Kaelen
	const FVector OptimalPos = KaelenLocation + BlindSpotOffset;
	const float Score = bIsKaelenUnbroken ? 100.0f : 40.0f;

	OnEQSFlankScoreEvaluated.Broadcast(OptimalPos, Score);

	UE_LOG(LogTemp, Warning, TEXT("UAshenGarrettFlankEQSEvaluator: GARRETT EQS BLIND-SPOT POSITION EVALUATED -> Location: (%s) | Score: %.0f (Unbroken: %s)."),
		*OptimalPos.ToString(), Score, bIsKaelenUnbroken ? TEXT("TRUE") : TEXT("FALSE"));

	return OptimalPos;
}
