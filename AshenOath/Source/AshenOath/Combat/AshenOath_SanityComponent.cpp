// Copyright Phoenix Protocol. All rights reserved.

#include "AshenOath_SanityComponent.h"
#include "Engine/World.h"

UAshenOath_SanityComponent::UAshenOath_SanityComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;

	MaxSanity = 100.0f;
	PassiveRecoveryRate = 2.0f;
	ShadowCostMultiplier = 1.5f;
	CurrentSanity = 0.0f;
	CurrentResonance = 0.0f;
}

void UAshenOath_SanityComponent::BeginPlay()
{
	Super::BeginPlay();

	CurrentSanity = MaxSanity;
	OnSanityChanged.Broadcast(CurrentSanity, MaxSanity);
}

void UAshenOath_SanityComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (PassiveRecoveryRate > 0.0f && CurrentSanity < MaxSanity)
	{
		HealSanity(PassiveRecoveryRate * DeltaTime);
	}
}

void UAshenOath_SanityComponent::SufferMentalDamage(float Amount)
{
	if (CurrentSanity <= 0.0f) return;

	CurrentSanity = FMath::Clamp(CurrentSanity - Amount, 0.0f, MaxSanity);
	OnSanityChanged.Broadcast(CurrentSanity, MaxSanity);

	if (CurrentSanity <= 0.0f)
	{
		OnSanityDepleted.Broadcast();
	}
}

void UAshenOath_SanityComponent::HealSanity(float Amount)
{
	if (Amount <= 0.0f) return;

	CurrentSanity = FMath::Clamp(CurrentSanity + Amount, 0.0f, MaxSanity);
	OnSanityChanged.Broadcast(CurrentSanity, MaxSanity);
}

void UAshenOath_SanityComponent::ConsumeShadowPower(float BaseCost)
{
	float TotalCost = BaseCost * ShadowCostMultiplier;
	CurrentResonance += TotalCost;

	SufferMentalDamage(TotalCost);
	OnInstabilitySpikeTriggered.Broadcast(TotalCost);
}

void UAshenOath_SanityComponent::SetCurrentSanity(float NewSanity)
{
	CurrentSanity = FMath::Clamp(NewSanity, 0.0f, MaxSanity);
	OnSanityChanged.Broadcast(CurrentSanity, MaxSanity);
}

void UAshenOath_SanityComponent::SetCurrentResonance(float NewResonance)
{
	CurrentResonance = NewResonance;
}
