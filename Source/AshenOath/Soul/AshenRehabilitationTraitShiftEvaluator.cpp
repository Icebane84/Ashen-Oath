// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Soul/AshenRehabilitationTraitShiftEvaluator.h"

UAshenRehabilitationTraitShiftEvaluator::UAshenRehabilitationTraitShiftEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenRehabilitationTraitShiftEvaluator::BeginPlay() { Super::BeginPlay(); }

void UAshenRehabilitationTraitShiftEvaluator::ApplyPermanentRehabilitationTraitBonuses(float IdentityPurityScore)
{
	PermanentPoiseBonusMultiplier = 1.0f + (IdentityPurityScore * 0.05f); // +5% poise at max purity
	StanceRecoveryBonusMultiplier = 1.0f + (IdentityPurityScore * 0.10f); // +10% stance recovery at max purity

	UE_LOG(LogTemp, Log, TEXT("UAshenRehabilitationTraitShiftEvaluator: Trait bonuses applied — Poise: %.2fx | Stance Recovery: %.2fx"),
		PermanentPoiseBonusMultiplier, StanceRecoveryBonusMultiplier);
}
