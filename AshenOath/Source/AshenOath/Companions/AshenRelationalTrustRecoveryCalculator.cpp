// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/AshenRelationalTrustRecoveryCalculator.h"
#include "Soul/AshenSoulPublisher.h"
#include "Soul/AshenSoulStateVector.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"

float UAshenRelationalTrustRecoveryCalculator::CalculateTrustRecovery(float CurrentTrust, float TacticalSynergyRating)
{
	const float NewTrust = FMath::Clamp(CurrentTrust + (TacticalSynergyRating * 0.15f), 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenRelationalTrustRecoveryCalculator: Trust recovered from %.2f to %.2f (Synergy: %.2f)"), CurrentTrust, NewTrust, TacticalSynergyRating);
	return NewTrust;
}

float UAshenRelationalTrustRecoveryCalculator::ApplyTrustRecovery(
	FName CompanionID,
	float TacticalSynergyRating,
	const UObject* WorldContextObject)
{
	if (TacticalSynergyRating <= 0.0f || !WorldContextObject) return 0.0f;

	const float RecoveryDelta = FMath::Clamp(TacticalSynergyRating * 0.15f, 0.02f, 0.30f);

	if (const UWorld* World = WorldContextObject->GetWorld())
	{
		if (const UGameInstance* GI = World->GetGameInstance())
		{
			if (UAshenSoulPublisher* Publisher = GI->GetSubsystem<UAshenSoulPublisher>())
			{
				FSoulStateVector Delta;
				Delta.Resolve = 0.05f;
				Delta.Corruption = 0.0f;
				Delta.IntegrationDebt = 0.0f;
				Delta.Isolation = -RecoveryDelta * 0.5f; // Closeness reduces isolation
				Delta.GarrettTrust = (CompanionID == FName("Garrett")) ? RecoveryDelta : 0.0f;
				Delta.SerafinaTrust = (CompanionID == FName("Serafina")) ? RecoveryDelta : 0.0f;
				Publisher->CommitState(Delta);

				const FSoulStateVector NewState = Publisher->GetSoulState();
				const float ResultTrust = (CompanionID == FName("Garrett")) ? NewState.GarrettTrust : NewState.SerafinaTrust;

				UE_LOG(LogTemp, Log, TEXT("UAshenRelationalTrustRecoveryCalculator: Applied +%.2f trust recovery to '%s' -> New Trust: %.2f"),
					RecoveryDelta, *CompanionID.ToString(), ResultTrust);

				return ResultTrust;
			}
		}
	}

	return 0.50f;
}
