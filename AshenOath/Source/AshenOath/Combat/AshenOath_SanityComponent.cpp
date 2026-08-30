// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenOath_SanityComponent.h"
#include "AshenAbilitySystemComponent.h"
#include "Soul/AshenSoulPublisher.h"
#include "Soul/AshenSoulTypes.h"
#include "Soul/AshenSoulStateVector.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"

UAshenOath_SanityComponent::UAshenOath_SanityComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	MaxSanity = 100.0f;
}

void UAshenOath_SanityComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenOath_SanityComponent::SufferMentalDamage(float Amount)
{
	if (Amount <= 0.0f) return;

	if (UAshenAbilitySystemComponent* ASC = GetOwnerASC())
	{
		ASC->ApplySanityDamage(Amount);
	}
	else if (UAshenSoulPublisher* Publisher = GetSoulPublisher())
	{
		const float NormalizedLoss = Amount / FMath::Max(1.0f, MaxSanity);
		FSoulStateVector Delta;
		Delta.Resolve = 0.0f;
		Delta.Corruption = NormalizedLoss * 0.50f;
		Delta.IntegrationDebt = 0.0f;
		Delta.Isolation = NormalizedLoss * 0.60f; // Canonical Dysregulation (N)
		Delta.GarrettTrust = 0.0f;
		Delta.SerafinaTrust = 0.0f;
		Publisher->CommitState(Delta);
	}

	const float Current = GetCurrentSanity();
	OnSanityChanged.Broadcast(Current, MaxSanity);

	if (Current <= 0.0f)
	{
		OnSanityDepleted.Broadcast();
	}
}

void UAshenOath_SanityComponent::HealSanity(float Amount)
{
	if (Amount <= 0.0f) return;

	if (UAshenSoulPublisher* Publisher = GetSoulPublisher())
	{
		const float NormalizedHeal = Amount / FMath::Max(1.0f, MaxSanity);
		FSoulStateVector Delta;
		Delta.Resolve = NormalizedHeal * 0.20f;
		Delta.Corruption = -NormalizedHeal * 0.30f;
		Delta.IntegrationDebt = 0.0f;
		Delta.Isolation = -NormalizedHeal * 0.40f;
		Delta.GarrettTrust = 0.0f;
		Delta.SerafinaTrust = 0.0f;
		Publisher->CommitState(Delta);
	}

	const float Current = GetCurrentSanity();
	OnSanityChanged.Broadcast(Current, MaxSanity);
}

void UAshenOath_SanityComponent::ConsumeShadowPower(float BaseCost)
{
	SufferMentalDamage(BaseCost);
	OnInstabilitySpikeTriggered.Broadcast(BaseCost * 1.5f);
}

float UAshenOath_SanityComponent::GetCurrentSanity() const
{
	if (UAshenAbilitySystemComponent* ASC = GetOwnerASC())
	{
		return ASC->GetCurrentSanity();
	}
	if (UAshenSoulPublisher* Publisher = GetSoulPublisher())
	{
		const FSoulStateVector State = Publisher->GetSoulState();
		return FMath::Clamp((1.0f - State.Corruption) * MaxSanity, 0.0f, MaxSanity);
	}
	return MaxSanity;
}

float UAshenOath_SanityComponent::GetCurrentResonance() const
{
	if (UAshenSoulPublisher* Publisher = GetSoulPublisher())
	{
		return Publisher->GetRelationalMatrix().TrioResonance;
	}
	return 0.70f;
}

void UAshenOath_SanityComponent::SetCurrentSanity(float NewSanity)
{
	const float Current = GetCurrentSanity();
	const float Diff = Current - NewSanity;
	if (Diff > 0.0f)
	{
		SufferMentalDamage(Diff);
	}
	else if (Diff < 0.0f)
	{
		HealSanity(-Diff);
	}
}

void UAshenOath_SanityComponent::SetCurrentResonance(float NewResonance)
{
	if (UAshenSoulPublisher* Publisher = GetSoulPublisher())
	{
		FRelationalMatrix_V2 RelMatrix = Publisher->GetRelationalMatrix();
		RelMatrix.TrioResonance = FMath::Clamp(NewResonance, 0.0f, 1.0f);
		Publisher->SetRelationalMatrix(RelMatrix);
	}
}

UAshenAbilitySystemComponent* UAshenOath_SanityComponent::GetOwnerASC() const
{
	if (const AActor* Owner = GetOwner())
	{
		return Owner->FindComponentByClass<UAshenAbilitySystemComponent>();
	}
	return nullptr;
}

UAshenSoulPublisher* UAshenOath_SanityComponent::GetSoulPublisher() const
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
