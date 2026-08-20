// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Companions/AshenCompanionTrustEventAdapter.h"

UAshenCompanionTrustEventAdapter::UAshenCompanionTrustEventAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenCompanionTrustEventAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenCompanionTrustEventAdapter::NotifyProtectiveAction(FName CompanionID)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenCompanionTrustEventAdapter: Protective action on %s logged (+0.05 Trust Event)."), *CompanionID.ToString());
}

void UAshenCompanionTrustEventAdapter::NotifyTacticalAbandonment(FName CompanionID)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenCompanionTrustEventAdapter: Tactical abandonment of %s logged (-0.08 Trust Event)."), *CompanionID.ToString());
}

void UAshenCompanionTrustEventAdapter::NotifyOathFulfilled()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenCompanionTrustEventAdapter: Living Oath fulfilled (+0.03 Trust to all companions)."));
}
