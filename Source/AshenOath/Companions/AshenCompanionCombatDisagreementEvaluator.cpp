// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/AshenCompanionCombatDisagreementEvaluator.h"

UAshenCompanionCombatDisagreementEvaluator::UAshenCompanionCombatDisagreementEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

bool UAshenCompanionCombatDisagreementEvaluator::EvaluateTargetEthosClash(const FSoulStateVector& StateVector, bool bIsNonHostileTarget)
{
	bool bClashDetected = bIsNonHostileTarget && (StateVector.Corruption < 0.6f);
	UE_LOG(LogTemp, Log, TEXT("UAshenCompanionCombatDisagreementEvaluator: Target ethos clash evaluation result: %s"), bClashDetected ? TEXT("CLASH") : TEXT("AGREE"));
	return bClashDetected;
}
