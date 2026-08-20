// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Companions/AshenMemoryPalaceCompanionAdapter.h"

UAshenMemoryPalaceCompanionAdapter::UAshenMemoryPalaceCompanionAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenMemoryPalaceCompanionAdapter::BeginPlay() { Super::BeginPlay(); }

float UAshenMemoryPalaceCompanionAdapter::EvaluateCompanionTrustBoostOnLocusUnsealed(FName CompanionID, EMemoryNodeType NodeType)
{
	float TrustBoost = 0.04f;
	if (NodeType == EMemoryNodeType::LorekeeperVault) TrustBoost = 0.08f;
	else if (NodeType == EMemoryNodeType::TraumaNexus) TrustBoost = 0.06f;

	UE_LOG(LogTemp, Log, TEXT("UAshenMemoryPalaceCompanionAdapter: Granted +%.2f Trust to %s upon unsealing locus node."),
		TrustBoost, *CompanionID.ToString());
	return TrustBoost;
}
