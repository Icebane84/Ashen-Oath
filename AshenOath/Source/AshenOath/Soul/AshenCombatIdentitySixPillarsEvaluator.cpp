// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 796: Ashen Combat Identity Six Pillars Evaluator

#include "AshenCombatIdentitySixPillarsEvaluator.h"

void UAshenCombatIdentitySixPillarsEvaluator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	TotalPillarsPassed = 6;
	UE_LOG(LogTemp, Log, TEXT("UAshenCombatIdentitySixPillarsEvaluator: Initialized — Six Pillars Evaluator ONLINE."));
}

bool UAshenCombatIdentitySixPillarsEvaluator::EvaluateCombatPillarCompliance(FName ActionTag, bool bIsDisciplinedTiming)
{
	const bool bPassed = bIsDisciplinedTiming;
	OnPillarEvaluated.Broadcast(ActionTag, bPassed);

	UE_LOG(LogTemp, Warning, TEXT("UAshenCombatIdentitySixPillarsEvaluator: SIX PILLARS EVALUATED -> Action: '%s' | Compliant: %s."),
		*ActionTag.ToString(), bPassed ? TEXT("PASS (Discipline > Aggression)") : TEXT("REJECT (Entropy/Button-Mashing)"));

	return bPassed;
}
