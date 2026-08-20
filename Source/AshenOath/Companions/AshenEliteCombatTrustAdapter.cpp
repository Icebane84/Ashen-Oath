// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Companions/AshenEliteCombatTrustAdapter.h"

UAshenEliteCombatTrustAdapter::UAshenEliteCombatTrustAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenEliteCombatTrustAdapter::BeginPlay() { Super::BeginPlay(); }

float UAshenEliteCombatTrustAdapter::AwardEliteParryTrust(FName CompanionID)
{
	const float Bonus = 0.08f;
	UE_LOG(LogTemp, Log, TEXT("UAshenEliteCombatTrustAdapter: +%.2f trust awarded to %s for parrying Shroud Knight warp strike!"),
		Bonus, *CompanionID.ToString());
	return Bonus;
}
