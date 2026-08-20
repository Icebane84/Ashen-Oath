// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Memory/AshenMemorySequenceUnlockEvaluator.h"

UAshenMemorySequenceUnlockEvaluator::UAshenMemorySequenceUnlockEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenMemorySequenceUnlockEvaluator::BeginPlay()
{
	Super::BeginPlay();
}

bool UAshenMemorySequenceUnlockEvaluator::EvaluateMemorySequenceEligibility(FName MemoryID, float IntegrationDebt)
{
	bool bEligible = IntegrationDebt <= 0.85f;
	UE_LOG(LogTemp, Log, TEXT("UAshenMemorySequenceUnlockEvaluator: Evaluated eligibility for memory %s (Eligible: %s)"), *MemoryID.ToString(), bEligible ? TEXT("True") : TEXT("False"));
	return bEligible;
}
