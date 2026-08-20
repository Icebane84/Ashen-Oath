// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 353: Ashen Companion Trust Divergence Subsystem

#include "AshenCompanionTrustDivergenceSubsystem.h"

void UAshenCompanionTrustDivergenceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	DivergenceRisks.Empty();
	UE_LOG(LogTemp, Log, TEXT("UAshenCompanionTrustDivergenceSubsystem: Initialized — Companion Divergence Tracker active."));
}

void UAshenCompanionTrustDivergenceSubsystem::EvaluateCompanionDivergenceRisk(FName CompanionID, float CurrentOathbondTrust)
{
	if (CompanionID.IsNone()) return;

	const float Risk = FMath::Clamp(100.0f - CurrentOathbondTrust, 0.0f, 100.0f);
	DivergenceRisks.Add(CompanionID, Risk);

	OnDivergenceRiskChanged.Broadcast(CompanionID, Risk);

	if (Risk >= 75.0f)
	{
		UE_LOG(LogTemp, Error, TEXT("UAshenCompanionTrustDivergenceSubsystem: CRITICAL DIVERGENCE RISK FOR '%s' — Risk: %.1f%% (Companion Betrayal Imminent!)."),
			*CompanionID.ToString(), Risk);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenCompanionTrustDivergenceSubsystem: Companion '%s' Divergence Risk: %.1f%%."),
			*CompanionID.ToString(), Risk);
	}
}

void UAshenCompanionTrustDivergenceSubsystem::RecordTrustShift(FName CompanionID, float TrustDelta)
{
	if (CompanionID.IsNone()) return;

	float CurrentRisk = DivergenceRisks.Contains(CompanionID) ? DivergenceRisks[CompanionID] : 0.0f;
	float NewRisk = FMath::Clamp(CurrentRisk - TrustDelta, 0.0f, 100.0f);
	DivergenceRisks.Add(CompanionID, NewRisk);

	OnDivergenceRiskChanged.Broadcast(CompanionID, NewRisk);

	UE_LOG(LogTemp, Warning, TEXT("UAshenCompanionTrustDivergenceSubsystem: TRUST SHIFT RECORDED FOR '%s' (%+f) -> Divergence Risk: %.1f%%."),
		*CompanionID.ToString(), TrustDelta, NewRisk);
}
