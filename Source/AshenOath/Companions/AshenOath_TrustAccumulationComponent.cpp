// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 553: Ashen Oath Trust Accumulation Component

#include "AshenOath_TrustAccumulationComponent.h"

UAshenOath_TrustAccumulationComponent::UAshenOath_TrustAccumulationComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	GarrettTrustAccumulator = 50.0f;
	SerafinaTrustAccumulator = 50.0f;
}

void UAshenOath_TrustAccumulationComponent::AccumulateTrustDelta(FName CompanionID, float Delta)
{
	if (CompanionID == FName(TEXT("Companion_Garrett")))
	{
		GarrettTrustAccumulator = FMath::Clamp(GarrettTrustAccumulator + Delta, 0.0f, 100.0f);
		OnTrustAccumulated.Broadcast(CompanionID, GarrettTrustAccumulator);
	}
	else if (CompanionID == FName(TEXT("Companion_Serafina")))
	{
		SerafinaTrustAccumulator = FMath::Clamp(SerafinaTrustAccumulator + Delta, 0.0f, 100.0f);
		OnTrustAccumulated.Broadcast(CompanionID, SerafinaTrustAccumulator);
	}

	UE_LOG(LogTemp, Log, TEXT("UAshenOath_TrustAccumulationComponent: TRUST ACCUMULATED -> Companion '%s' (Delta: %+.1f)."),
		*CompanionID.ToString(), Delta);
}

float UAshenOath_TrustAccumulationComponent::GetTrust(const FAshenOathTrustPairKey& Key) const
{
	if (const FAshenOathTrustPairState* State = PairStates.Find(Key))
	{
		return State->Trust;
	}

	if (Key.Trustee == EAshenOathCompanion::Garrett) return GarrettTrustAccumulator / 100.0f;
	if (Key.Trustee == EAshenOathCompanion::Serafina) return SerafinaTrustAccumulator / 100.0f;

	return 0.5f;
}

EAshenOathTrustBand UAshenOath_TrustAccumulationComponent::GetTrustBand(const FAshenOathTrustPairKey& Key) const
{
	const float Val = GetTrust(Key);
	if (Val >= 0.8f) return EAshenOathTrustBand::Synchronized;
	if (Val >= 0.6f) return EAshenOathTrustBand::Cooperative;
	if (Val >= 0.4f) return EAshenOathTrustBand::Cautious;
	return EAshenOathTrustBand::Guarded;
}

void UAshenOath_TrustAccumulationComponent::InitializePairTrust(const FAshenOathTrustPairKey& Key, float InitialValue)
{
	FAshenOathTrustPairState& State = PairStates.FindOrAdd(Key);
	State.Trust = InitialValue;
}

float UAshenOath_TrustAccumulationComponent::UpdateTrust(const FAshenOathTrustPairKey& Key, float Penalty, float Weight, double Timestamp)
{
	FAshenOathTrustPairState& State = PairStates.FindOrAdd(Key);
	State.Trust = FMath::Clamp(State.Trust - Penalty + Weight, 0.0f, 1.0f);
	State.LastEventTimestamp = Timestamp;
	State.CurrentBand = GetTrustBand(Key);

	return State.Trust;
}
