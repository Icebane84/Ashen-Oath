// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Companions/AshenLivingCodexCompanionAdapter.h"

UAshenLivingCodexCompanionAdapter::UAshenLivingCodexCompanionAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenLivingCodexCompanionAdapter::BeginPlay() { Super::BeginPlay(); }

float UAshenLivingCodexCompanionAdapter::EvaluateCompanionTrustGain(FName EntryID, FName CompanionID)
{
	float TrustGain = 0.02f; // Base lore discovery bonus

	const FString EntryStr = EntryID.ToString();
	if (EntryStr.Contains(CompanionID.ToString()))
	{
		TrustGain = 0.08f; // Major personal backstory bonus
		UE_LOG(LogTemp, Warning, TEXT("UAshenLivingCodexCompanionAdapter: Major personal backstory unsealed for %s! (+%.2f Trust)."),
			*CompanionID.ToString(), TrustGain);
	}

	return TrustGain;
}
