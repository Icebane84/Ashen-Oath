// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Companions/AshenFinisherCompanionTrustAdapter.h"

UAshenFinisherCompanionTrustAdapter::UAshenFinisherCompanionTrustAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenFinisherCompanionTrustAdapter::BeginPlay() { Super::BeginPlay(); }

float UAshenFinisherCompanionTrustAdapter::AwardFinisherTrust(EAshenPartyFinisherType FinisherType, FName CompanionID)
{
	const float TrustBonus = 0.12f;
	UE_LOG(LogTemp, Log, TEXT("UAshenFinisherCompanionTrustAdapter: +%.2f Trust awarded to %s after Finisher Type %d!"),
		TrustBonus, *CompanionID.ToString(), (int32)FinisherType);
	return TrustBonus;
}
