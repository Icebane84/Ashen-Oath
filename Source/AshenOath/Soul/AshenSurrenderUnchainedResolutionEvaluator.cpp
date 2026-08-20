// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 824: Ashen Surrender Unchained Resolution Evaluator

#include "AshenSurrenderUnchainedResolutionEvaluator.h"

void UAshenSurrenderUnchainedResolutionEvaluator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	TotalSurrendersExecuted = 0;
	UE_LOG(LogTemp, Log, TEXT("UAshenSurrenderUnchainedResolutionEvaluator: Initialized — Surrender Unchained Resolution Evaluator ONLINE."));
}

void UAshenSurrenderUnchainedResolutionEvaluator::ExecuteSurrenderUnchainedResolution()
{
	TotalSurrendersExecuted++;
	const FName StanceTag = FName(TEXT("Stance.UnchainedBerserk"));
	const float AttackSpeedMult = 2.0f; // Attack speed doubles instantly

	OnSurrenderExecuted.Broadcast(StanceTag, AttackSpeedMult);

	UE_LOG(LogTemp, Warning, TEXT("UAshenSurrenderUnchainedResolutionEvaluator: SURRENDER TO DARK MODE EXECUTED -> Stance: '%s' | Attack Speed: %.1fx | HUD Removed | Trust Atrophy Incurred."),
		*StanceTag.ToString(), AttackSpeedMult);
}
