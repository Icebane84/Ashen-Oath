// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Companions/AshenSerafinaBurnoutReceiverComponent.h"

UAshenSerafinaBurnoutReceiverComponent::UAshenSerafinaBurnoutReceiverComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CumulativeBurnout = 0.0f;
	CurrentTier = EBurnoutSeverityTier::Nominal;
}

FTransferenceBurdenSnapshot UAshenSerafinaBurnoutReceiverComponent::AbsorbTraumaPayload(float RawTrauma)
{
	CumulativeBurnout = FMath::Clamp(CumulativeBurnout + RawTrauma, 0.0f, 100.0f);

	if (CumulativeBurnout < 25.0f)
	{
		CurrentTier = EBurnoutSeverityTier::Nominal;
	}
	else if (CumulativeBurnout < 50.0f)
	{
		CurrentTier = EBurnoutSeverityTier::Strained;
	}
	else if (CumulativeBurnout < 80.0f)
	{
		CurrentTier = EBurnoutSeverityTier::Exhausted;
	}
	else
	{
		CurrentTier = EBurnoutSeverityTier::CriticalCollapse;
	}

	FTransferenceBurdenSnapshot Snapshot;
	Snapshot.TransferenceId = FGuid::NewGuid().ToString(EGuidFormats::DigitsWithHyphensLower);
	Snapshot.TraumaAbsorbed = RawTrauma;
	Snapshot.SerafinaCumulativeBurnout = CumulativeBurnout;
	Snapshot.BurnoutTier = CurrentTier;

	// Scale recovery delay penalty from 0.0s to 0.60s based on tier
	Snapshot.RecoveryDelayPenaltySeconds = (static_cast<uint8>(CurrentTier) * 0.20f);

	return Snapshot;
}

void UAshenSerafinaBurnoutReceiverComponent::ResetBurnoutAtCampfire()
{
	CumulativeBurnout = 0.0f;
	CurrentTier = EBurnoutSeverityTier::Nominal;
}
