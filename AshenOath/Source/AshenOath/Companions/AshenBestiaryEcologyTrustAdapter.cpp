// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Companions/AshenBestiaryEcologyTrustAdapter.h"

UAshenBestiaryEcologyTrustAdapter::UAshenBestiaryEcologyTrustAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenBestiaryEcologyTrustAdapter::BeginPlay() { Super::BeginPlay(); }

float UAshenBestiaryEcologyTrustAdapter::AwardEcologyFinisherTrust(EAshenPartyFinisherType FinisherType, FName CompanionID)
{
	const float TrustBonus = 0.15f;
	UE_LOG(LogTemp, Log, TEXT("UAshenBestiaryEcologyTrustAdapter: +%.2f Trust awarded to %s after Bestiary Finisher Type %d!"),
		TrustBonus, *CompanionID.ToString(), (int32)FinisherType);
	return TrustBonus;
}
