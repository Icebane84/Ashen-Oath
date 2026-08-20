// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Companions/AshenOathCompanionTrustAdapter.h"

UAshenOathCompanionTrustAdapter::UAshenOathCompanionTrustAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenOathCompanionTrustAdapter::BeginPlay() { Super::BeginPlay(); }

float UAshenOathCompanionTrustAdapter::EvaluateOathTrustImpact(EAshenLivingOathType OathType, bool bOathFulfilled, FName CompanionID)
{
	float TrustDelta = bOathFulfilled ? 0.15f : -0.25f;
	UE_LOG(LogTemp, Log, TEXT("UAshenOathCompanionTrustAdapter: Trust impact for %s on Oath %d: %.2f"),
		*CompanionID.ToString(), (int32)OathType, TrustDelta);
	return TrustDelta;
}
