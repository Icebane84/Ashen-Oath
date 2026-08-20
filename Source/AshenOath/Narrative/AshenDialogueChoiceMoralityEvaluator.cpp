// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 758: Ashen Dialogue Choice Morality Evaluator

#include "AshenDialogueChoiceMoralityEvaluator.h"

void UAshenDialogueChoiceMoralityEvaluator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	ActiveWhiteFlameVector = 50.0f;
	ActiveCorruptionVector = 50.0f;
	UE_LOG(LogTemp, Log, TEXT("UAshenDialogueChoiceMoralityEvaluator: Initialized — Dialogue Choice Morality Evaluator ONLINE."));
}

void UAshenDialogueChoiceMoralityEvaluator::EvaluateDialogueChoice(FName ChoiceID, float WhiteFlameDelta, float CorruptionDelta)
{
	ActiveWhiteFlameVector = FMath::Clamp(ActiveWhiteFlameVector + WhiteFlameDelta, 0.0f, 100.0f);
	ActiveCorruptionVector = FMath::Clamp(ActiveCorruptionVector + CorruptionDelta, 0.0f, 100.0f);

	OnMoralityEvaluated.Broadcast(ChoiceID, ActiveWhiteFlameVector, ActiveCorruptionVector);

	UE_LOG(LogTemp, Warning, TEXT("UAshenDialogueChoiceMoralityEvaluator: DIALOGUE CHOICE EVALUATED -> Choice ID: '%s' | White Flame Vector: %.1f | Corruption Vector: %.1f."),
		*ChoiceID.ToString(), ActiveWhiteFlameVector, ActiveCorruptionVector);
}
