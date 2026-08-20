// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Companions/AshenAdvancedCombatTrustAdapter.h"

UAshenAdvancedCombatTrustAdapter::UAshenAdvancedCombatTrustAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenAdvancedCombatTrustAdapter::BeginPlay() { Super::BeginPlay(); }

float UAshenAdvancedCombatTrustAdapter::AwardParryTrustBonus(FName CompanionID)
{
	const float Bonus = 0.05f;
	UE_LOG(LogTemp, Log, TEXT("UAshenAdvancedCombatTrustAdapter: +%.2f trust awarded to %s for witnessed parry execution!"),
		Bonus, *CompanionID.ToString());
	return Bonus;
}
