// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 704: Ashen Garrett Flash Powder Blind Evaluator

#include "AshenGarrettFlashPowderBlindEvaluator.h"

float UAshenGarrettFlashPowderBlindEvaluator::EvaluateFlashPowderBlindImpact(float DistanceFromExplosion, float EnemyPerceptionScore)
{
	const float DistanceEfficiency = FMath::Clamp(1.0f - (DistanceFromExplosion / 600.0f), 0.1f, 1.0f);
	const float Duration = FMath::Clamp(5.0f * DistanceEfficiency, 1.0f, 5.0f);
	const float AccuracyPenalty = 75.0f * DistanceEfficiency;

	OnBlindEvaluated.Broadcast(Duration, AccuracyPenalty);

	UE_LOG(LogTemp, Warning, TEXT("UAshenGarrettFlashPowderBlindEvaluator: FLASH POWDER BLIND EVALUATED -> Distance: %.1f | Duration: %.1fs | Accuracy Penalty: -%.0f%%."),
		DistanceFromExplosion, Duration, AccuracyPenalty);

	return Duration;
}
