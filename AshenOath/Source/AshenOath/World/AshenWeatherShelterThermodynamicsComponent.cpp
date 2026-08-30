// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenWeatherShelterThermodynamicsComponent.h"
#include "Soul/AshenSoulPublisher.h"
#include "Soul/AshenSoulTypes.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"

UAshenWeatherShelterThermodynamicsComponent::UAshenWeatherShelterThermodynamicsComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CurrentShelterTier = EAshenShelterTier::Wilderness;
	WildernessDebtAccumulationRate = 0.02f;
	HavenDebtPurgeRate = 0.05f;
}

void UAshenWeatherShelterThermodynamicsComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenWeatherShelterThermodynamicsComponent::SetShelterTier(EAshenShelterTier NewTier)
{
	if (CurrentShelterTier != NewTier)
	{
		const EAshenShelterTier OldTier = CurrentShelterTier;
		CurrentShelterTier = NewTier;
		OnShelterTierChanged.Broadcast(OldTier, NewTier);

		UE_LOG(LogTemp, Log, TEXT("AshenWeatherShelter: Shelter tier transitioned from %d to %d"), (int32)OldTier, (int32)NewTier);
	}
}

void UAshenWeatherShelterThermodynamicsComponent::TickEnvironmentalExposure(float DeltaTime)
{
	if (DeltaTime <= 0.0f)
	{
		return;
	}

	UAshenSoulPublisher* Publisher = GetSoulPublisher();
	if (!Publisher)
	{
		return;
	}

	if (CurrentShelterTier == EAshenShelterTier::Wilderness)
	{
		// Unsheltered exposure accumulates Integration Debt
		FSoulStateVector Delta;
		Delta.Resolve = 0.0f;
		Delta.Corruption = 0.0f;
		Delta.IntegrationDebt = WildernessDebtAccumulationRate * DeltaTime;
		Delta.Isolation = 0.0f;
		Delta.GarrettTrust = 0.0f;
		Delta.SerafinaTrust = 0.0f;

		Publisher->CommitState(Delta);
	}
	else if (CurrentShelterTier == EAshenShelterTier::HavenBrazier)
	{
		// Haven Brazier actively purges Integration Debt
		FSoulStateVector Delta;
		Delta.Resolve = 0.0f;
		Delta.Corruption = 0.0f;
		Delta.IntegrationDebt = -HavenDebtPurgeRate * DeltaTime;
		Delta.Isolation = 0.0f;
		Delta.GarrettTrust = 0.0f;
		Delta.SerafinaTrust = 0.0f;

		Publisher->CommitState(Delta);
	}
}

float UAshenWeatherShelterThermodynamicsComponent::GetEffectiveExposureRate() const
{
	switch (CurrentShelterTier)
	{
	case EAshenShelterTier::Wilderness:
		return -2.5f;
	case EAshenShelterTier::CavernCover:
		return 0.0f;
	case EAshenShelterTier::HavenBrazier:
		return 0.0f; // 100% immune
	default:
		return 0.0f;
	}
}

UAshenSoulPublisher* UAshenWeatherShelterThermodynamicsComponent::GetSoulPublisher() const
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
