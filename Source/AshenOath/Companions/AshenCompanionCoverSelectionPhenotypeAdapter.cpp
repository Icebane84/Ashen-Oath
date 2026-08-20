// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/AshenCompanionCoverSelectionPhenotypeAdapter.h"

UAshenCompanionCoverSelectionPhenotypeAdapter::UAshenCompanionCoverSelectionPhenotypeAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenCompanionCoverSelectionPhenotypeAdapter::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	CoverAggressiveness = FMath::Clamp((NewState.GarrettTrust * 0.7f) + (NewState.Resolve * 0.3f), 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenCompanionCoverSelectionPhenotypeAdapter: Garrett cover selection aggressiveness updated to %.2f"), CoverAggressiveness);
}
