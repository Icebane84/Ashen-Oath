// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 804: Ashen Devil's Bargain Hesitation Protocol Evaluator

#include "AshenDevilsBargainHesitationProtocolEvaluator.h"

void UAshenDevilsBargainHesitationProtocolEvaluator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenDevilsBargainHesitationProtocolEvaluator: Initialized — Hesitation Protocol Evaluator ONLINE."));
}

FName UAshenDevilsBargainHesitationProtocolEvaluator::EvaluateHesitationOutcome(bool bIsAllyNearby)
{
	FName OutcomeTag = FName(TEXT("Outcome.SoloInactionPoiseBreak"));
	bool bSurgeGranted = false;

	if (bIsAllyNearby)
	{
		OutcomeTag = FName(TEXT("Outcome.MartyrsGuardStepIn"));
		bSurgeGranted = true;
	}

	OnOutcomeEvaluated.Broadcast(OutcomeTag, bSurgeGranted);

	UE_LOG(LogTemp, Warning, TEXT("UAshenDevilsBargainHesitationProtocolEvaluator: HESITATION PROTOCOL EVALUATED -> Ally Nearby: %s | Outcome: '%s' | White Flame Surge: %s."),
		bIsAllyNearby ? TEXT("TRUE") : TEXT("FALSE"), *OutcomeTag.ToString(), bSurgeGranted ? TEXT("GRANTED") : TEXT("NONE"));

	return OutcomeTag;
}
