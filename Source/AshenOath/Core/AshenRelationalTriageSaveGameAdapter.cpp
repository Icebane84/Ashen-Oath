// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Core/AshenRelationalTriageSaveGameAdapter.h"

UAshenRelationalTriageSaveGameAdapter::UAshenRelationalTriageSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenRelationalTriageSaveGameAdapter::BeginPlay() { Super::BeginPlay(); }

bool UAshenRelationalTriageSaveGameAdapter::SaveTriageHistory(const TArray<FTriageIncidentRecord>& Incidents, const FPairwiseTrustVector& Trust)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenRelationalTriageSaveGameAdapter: Saved %d Triage Incidents | K->S Trust: %.2f"),
		Incidents.Num(), Trust.KaelenToSerafinaTrust);
	return true;
}
