// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenCompanionTrustDialogueTreeAdapter.h"

UAshenCompanionTrustDialogueTreeAdapter::UAshenCompanionTrustDialogueTreeAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenCompanionTrustDialogueTreeAdapter::BeginPlay() { Super::BeginPlay(); }

bool UAshenCompanionTrustDialogueTreeAdapter::IsDialogueNodeUnlockedByTrust(FName CompanionID, FName NodeID, float CurrentTrust)
{
	const bool bUnlocked = CurrentTrust >= 0.50f;
	UE_LOG(LogTemp, Log, TEXT("UAshenCompanionTrustDialogueTreeAdapter: Dialogue node '%s' for %s (Trust: %.2f) -> %s"),
		*NodeID.ToString(), *CompanionID.ToString(), CurrentTrust, bUnlocked ? TEXT("UNLOCKED") : TEXT("LOCKED"));
	return bUnlocked;
}
