// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 588: Ashen Blessing Buff Component

#include "AshenBlessingBuffComponent.h"

UAshenBlessingBuffComponent::UAshenBlessingBuffComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	ActiveStatModifierPercent = 0.0f;
}

void UAshenBlessingBuffComponent::ApplyBlessingBuff(FName BlessingID, float StatModifierPercent)
{
	ActiveBlessingID = BlessingID;
	ActiveStatModifierPercent = StatModifierPercent;

	OnBlessingBuffApplied.Broadcast(BlessingID, StatModifierPercent);

	UE_LOG(LogTemp, Warning, TEXT("UAshenBlessingBuffComponent: BLESSING BUFF APPLIED -> '%s' (+%.1f%% Stat Modifier)."),
		*BlessingID.ToString(), StatModifierPercent);
}
