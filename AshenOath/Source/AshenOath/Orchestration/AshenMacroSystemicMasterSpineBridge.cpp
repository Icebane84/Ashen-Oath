// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Orchestration/AshenMacroSystemicMasterSpineBridge.h"

UAshenMacroSystemicMasterSpineBridge::UAshenMacroSystemicMasterSpineBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenMacroSystemicMasterSpineBridge::ArbitrateTriggerResistance(
	ETriggerResistanceSource ActiveSource,
	float DialogueResistance,
	float CombatBaselineResistance,
	float AmbientIntentResistance,
	bool bCombatPoiseBroken)
{
	switch (ActiveSource)
	{
	case ETriggerResistanceSource::DialogueWillStruggle:
		// Priority 1: Dialogue Squeeze (>=0.85 locks trigger to 1.0, otherwise applies continuous spring tension)
		return (DialogueResistance >= 0.85f) ? 1.0f : FMath::Clamp(DialogueResistance, 0.0f, 1.0f);

	case ETriggerResistanceSource::CombatStagger:
		// Priority 2: Combat Stagger Pivot (Poise break drops flat 0.50 baseline instantly to 0.0 give-way)
		return bCombatPoiseBroken ? 0.0f : FMath::Clamp(CombatBaselineResistance, 0.0f, 1.0f);

	case ETriggerResistanceSource::AmbientSomatic:
	default:
		// Priority 3: Continuous Ambient Somatic baseline
		return FMath::Clamp(AmbientIntentResistance, 0.0f, 0.35f);
	}
}

void UAshenMacroSystemicMasterSpineBridge::BroadcastTraumaImprintCreated(const FMemoryImprintPayload& Payload)
{
	OnTraumaImprintCreated.Broadcast(Payload);
}

void UAshenMacroSystemicMasterSpineBridge::BroadcastTrialOfWillResolved(
	EWillContext Context,
	EWillTrialResult Result,
	float CompletionRatio,
	FGuid SourceTransactionId)
{
	OnTrialOfWillResolved.Broadcast(Context, Result, CompletionRatio, SourceTransactionId);
}
