// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Core/AshenCompanionTrustNPCReactivityAdapter.h"

UAshenCompanionTrustNPCReactivityAdapter::UAshenCompanionTrustNPCReactivityAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenCompanionTrustNPCReactivityAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenCompanionTrustNPCReactivityAdapter::UpdateNPCReactivityForCompanionTrust(float GarrettTrust, float SerafinaTrust)
{
	const float AvgTrust = (GarrettTrust + SerafinaTrust) * 0.5f;
	TownMerchantDiscountFactor = FMath::Lerp(1.15f, 0.85f, AvgTrust);
	UE_LOG(LogTemp, Log, TEXT("UAshenCompanionTrustNPCReactivityAdapter: NPC reactivity updated — Merchant Discount Factor: %.2fx"), TownMerchantDiscountFactor);
}
