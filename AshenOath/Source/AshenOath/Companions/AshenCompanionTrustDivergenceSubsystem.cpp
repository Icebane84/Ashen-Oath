// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenCompanionTrustDivergenceSubsystem.h"
#include "Soul/AshenSoulPublisher.h"
#include "Soul/AshenSoulStateVector.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"

void UAshenCompanionTrustDivergenceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenCompanionTrustDivergenceSubsystem: Initialized — Zero-Entropy SSoT Divergence Tracker active."));
}

float UAshenCompanionTrustDivergenceSubsystem::EvaluateCompanionDivergenceRisk(FName CompanionID)
{
	const float Risk = GetDivergenceRisk(CompanionID);
	OnDivergenceRiskChanged.Broadcast(CompanionID, Risk * 100.0f);

	if (Risk >= 0.75f)
	{
		UE_LOG(LogTemp, Error, TEXT("UAshenCompanionTrustDivergenceSubsystem: CRITICAL DIVERGENCE RISK FOR '%s' — Risk: %.1f%% (Companion Betrayal Imminent!)."),
			*CompanionID.ToString(), Risk * 100.0f);
	}
	return Risk;
}

float UAshenCompanionTrustDivergenceSubsystem::GetDivergenceRisk(FName CompanionID) const
{
	if (CompanionID.IsNone()) return 0.0f;

	if (UAshenSoulPublisher* Publisher = GetSoulPublisher())
	{
		const FRelationalMatrix_V2 Matrix = Publisher->GetRelationalMatrix();
		if (CompanionID == FName("Garrett"))
		{
			// Garrett divergence driven by Somatic Dread tempered by trust
			return FMath::Clamp(Matrix.GarrettProfile.SomaticDread * (1.0f - Matrix.GarrettProfile.InterpersonalTrust * 0.5f), 0.0f, 1.0f);
		}
		if (CompanionID == FName("Serafina"))
		{
			// Serafina divergence driven by Transference Burnout tempered by trust
			return FMath::Clamp(Matrix.SerafinaProfile.TransferenceBurnout * (1.0f - Matrix.SerafinaProfile.InterpersonalTrust * 0.5f), 0.0f, 1.0f);
		}
	}
	return 0.20f;
}

void UAshenCompanionTrustDivergenceSubsystem::RecordTrustShift(FName CompanionID, float NormalizedTrustDelta)
{
	if (CompanionID.IsNone()) return;

	if (UAshenSoulPublisher* Publisher = GetSoulPublisher())
	{
		FSoulStateVector Delta;
		Delta.Resolve = 0.0f;
		Delta.Corruption = 0.0f;
		Delta.IntegrationDebt = 0.0f;
		Delta.Isolation = 0.0f;
		Delta.GarrettTrust = (CompanionID == FName("Garrett")) ? NormalizedTrustDelta : 0.0f;
		Delta.SerafinaTrust = (CompanionID == FName("Serafina")) ? NormalizedTrustDelta : 0.0f;
		Publisher->CommitState(Delta);

		EvaluateCompanionDivergenceRisk(CompanionID);
	}
}

UAshenSoulPublisher* UAshenCompanionTrustDivergenceSubsystem::GetSoulPublisher() const
{
	if (const UWorld* World = GetWorld())
	{
		if (const UGameInstance* GI = World->GetGameInstance())
		{
			return GI->GetSubsystem<UAshenSoulPublisher>();
		}
	}
	return nullptr;
}
