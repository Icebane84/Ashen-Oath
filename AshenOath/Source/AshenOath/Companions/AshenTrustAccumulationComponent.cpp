// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenTrustAccumulationComponent.h"
#include "Soul/AshenSoulPublisher.h"
#include "Soul/AshenSoulTypes.h"
#include "Soul/AshenSoulStateVector.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"

UAshenTrustAccumulationComponent::UAshenTrustAccumulationComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	MaxTrustScore = 100.0f;
}

void UAshenTrustAccumulationComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenTrustAccumulationComponent::AddTrust(FName CompanionName, float TrustDelta)
{
	if (CompanionName.IsNone()) return;

	UAshenSoulPublisher* Publisher = GetSoulPublisher();
	if (!Publisher) return;

	const float NormalizedDelta = TrustDelta / FMath::Max(1.0f, MaxTrustScore);

	FSoulStateVector Delta;
	Delta.Resolve = 0.0f;
	Delta.Corruption = 0.0f;
	Delta.IntegrationDebt = 0.0f;
	Delta.Isolation = 0.0f;
	Delta.GarrettTrust = (CompanionName == FName("Garrett")) ? NormalizedDelta : 0.0f;
	Delta.SerafinaTrust = (CompanionName == FName("Serafina")) ? NormalizedDelta : 0.0f;

	Publisher->CommitState(Delta);

	const float NewScore = GetTrustScore(CompanionName);
	OnTrustChanged.Broadcast(CompanionName, NewScore);

	UE_LOG(LogTemp, Log, TEXT("UAshenTrustAccumulationComponent: Committed canonical trust delta for '%s' -> %.1f"),
		*CompanionName.ToString(), NewScore);
}

float UAshenTrustAccumulationComponent::GetTrustScore(FName CompanionName) const
{
	if (UAshenSoulPublisher* Publisher = GetSoulPublisher())
	{
		const FSoulStateVector State = Publisher->GetSoulState();
		if (CompanionName == FName("Garrett"))
		{
			return State.GarrettTrust * MaxTrustScore;
		}
		if (CompanionName == FName("Serafina"))
		{
			return State.SerafinaTrust * MaxTrustScore;
		}
	}
	return 50.0f; // Default baseline (0.50 * 100)
}

float UAshenTrustAccumulationComponent::GetSynergyDamageMultiplier(FName CompanionName) const
{
	if (UAshenSoulPublisher* Publisher = GetSoulPublisher())
	{
		const FRelationalMatrix_V2 RelMatrix = Publisher->GetRelationalMatrix();
		if (CompanionName == FName("Garrett"))
		{
			return 1.0f + (RelMatrix.GarrettProfile.TacticalConfidence * 0.50f);
		}
		if (CompanionName == FName("Serafina"))
		{
			return 1.0f + (RelMatrix.SerafinaProfile.TacticalConfidence * 0.50f);
		}
	}
	const float Score = GetTrustScore(CompanionName);
	return 1.0f + (Score / MaxTrustScore) * 0.50f;
}

UAshenSoulPublisher* UAshenTrustAccumulationComponent::GetSoulPublisher() const
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
