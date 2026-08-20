// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Companions/AshenMemoryCompanionTrustAdapter.h"

UAshenMemoryCompanionTrustAdapter::UAshenMemoryCompanionTrustAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenMemoryCompanionTrustAdapter::BeginPlay() { Super::BeginPlay(); }

float UAshenMemoryCompanionTrustAdapter::EvaluateMemoryTrustDelta(FName EchoID, bool bVictory, FName CompanionID)
{
	float TrustDelta = bVictory ? 0.12f : -0.05f;
	UE_LOG(LogTemp, Log, TEXT("UAshenMemoryCompanionTrustAdapter: Trust delta for %s after Echo '%s' resolution: %.2f"),
		*CompanionID.ToString(), *EchoID.ToString(), TrustDelta);
	return TrustDelta;
}
