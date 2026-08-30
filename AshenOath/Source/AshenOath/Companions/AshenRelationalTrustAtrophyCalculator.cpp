// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/AshenRelationalTrustAtrophyCalculator.h"
#include "Soul/AshenSoulPublisher.h"
#include "Soul/AshenSoulStateVector.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"

float UAshenRelationalTrustAtrophyCalculator::CalculateTrustAtrophy(float CurrentTrust, int32 IgnoredAdviceCount)
{
	const float Decay = FMath::Min(IgnoredAdviceCount * 0.05f, 0.40f);
	const float NewTrust = FMath::Clamp(CurrentTrust - Decay, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenRelationalTrustAtrophyCalculator: Trust decay calculated -> NewTrust: %.2f (Ignored: %d)"), NewTrust, IgnoredAdviceCount);
	return NewTrust;
}

float UAshenRelationalTrustAtrophyCalculator::ApplyTrustAtrophy(
	FName CompanionID,
	int32 IgnoredAdviceCount,
	const UObject* WorldContextObject)
{
	if (IgnoredAdviceCount <= 0 || !WorldContextObject) return 0.0f;

	const float DecayDelta = FMath::Min(IgnoredAdviceCount * 0.05f, 0.40f);

	if (const UWorld* World = WorldContextObject->GetWorld())
	{
		if (const UGameInstance* GI = World->GetGameInstance())
		{
			if (UAshenSoulPublisher* Publisher = GI->GetSubsystem<UAshenSoulPublisher>())
			{
				FSoulStateVector Delta;
				Delta.Resolve = 0.0f;
				Delta.Corruption = 0.0f;
				Delta.IntegrationDebt = 0.0f;
				Delta.Isolation = DecayDelta * 0.5f; // Growing distance adds slight dysregulation
				Delta.GarrettTrust = (CompanionID == FName("Garrett")) ? -DecayDelta : 0.0f;
				Delta.SerafinaTrust = (CompanionID == FName("Serafina")) ? -DecayDelta : 0.0f;
				Publisher->CommitState(Delta);

				const FSoulStateVector NewState = Publisher->GetSoulState();
				const float ResultTrust = (CompanionID == FName("Garrett")) ? NewState.GarrettTrust : NewState.SerafinaTrust;

				UE_LOG(LogTemp, Warning, TEXT("UAshenRelationalTrustAtrophyCalculator: Applied -%.2f trust atrophy to '%s' -> New Trust: %.2f"),
					DecayDelta, *CompanionID.ToString(), ResultTrust);

				return ResultTrust;
			}
		}
	}

	return 0.50f;
}
