// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Companions/AshenCampfireCompanionTrustAdapter.h"

UAshenCampfireCompanionTrustAdapter::UAshenCampfireCompanionTrustAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenCampfireCompanionTrustAdapter::BeginPlay() { Super::BeginPlay(); }

float UAshenCampfireCompanionTrustAdapter::AwardCampfireConversationTrust(FName CompanionID)
{
	const float Bonus = 0.10f;
	UE_LOG(LogTemp, Log, TEXT("UAshenCampfireCompanionTrustAdapter: +%.2f trust awarded to %s during campfire rest dialogue!"),
		Bonus, *CompanionID.ToString());
	return Bonus;
}
