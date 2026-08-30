// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenMartyrGuardCorruptionSpikeCalculator.h"
#include "Soul/AshenSoulPublisher.h"
#include "Soul/AshenSoulStateVector.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"

float UAshenMartyrGuardCorruptionSpikeCalculator::CalculateMartyrCorruptionSpike(float InterceptedLethalDamage, float LegacyUnusedCorruption)
{
	// Normalized spike calculation: 1000 damage yields 0.25 corruption spike (bounded [0.05, 0.35])
	const float Spike = FMath::Clamp((InterceptedLethalDamage / 1000.0f) * 0.25f, 0.05f, 0.35f);

	float TotalCorruption = Spike;
	if (UAshenSoulPublisher* Publisher = GetSoulPublisher())
	{
		FSoulStateVector Delta;
		Delta.Resolve = 0.0f;
		Delta.Corruption = Spike;
		Delta.IntegrationDebt = 0.10f; // Intercepting adds +0.10 Integration Debt
		Delta.Isolation = 0.0f;
		Delta.GarrettTrust = 0.05f; // Companion gratitude increases trust
		Delta.SerafinaTrust = 0.05f;
		Publisher->CommitState(Delta);

		TotalCorruption = Publisher->GetSoulState().Corruption;
	}

	OnCorruptionSpikeCalculated.Broadcast(Spike, TotalCorruption);

	UE_LOG(LogTemp, Log, TEXT("UAshenMartyrGuardCorruptionSpikeCalculator: Intercepted %f dmg -> Spike: +%f | Total Corruption: %f"),
		InterceptedLethalDamage, Spike, TotalCorruption);

	return Spike;
}

UAshenSoulPublisher* UAshenMartyrGuardCorruptionSpikeCalculator::GetSoulPublisher() const
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
