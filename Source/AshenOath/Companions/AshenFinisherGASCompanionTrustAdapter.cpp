// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Companions/AshenFinisherGASCompanionTrustAdapter.h"

UAshenFinisherGASCompanionTrustAdapter::UAshenFinisherGASCompanionTrustAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenFinisherGASCompanionTrustAdapter::BeginPlay() { Super::BeginPlay(); }

float UAshenFinisherGASCompanionTrustAdapter::EvaluateFinisherGASTrustPayout(FName AbilityName, FName CompanionID)
{
	const float TrustBonus = 0.15f;
	UE_LOG(LogTemp, Log, TEXT("UAshenFinisherGASCompanionTrustAdapter: +%.2f Trust awarded to %s after completing '%s'."),
		TrustBonus, *CompanionID.ToString(), *AbilityName.ToString());
	return TrustBonus;
}
