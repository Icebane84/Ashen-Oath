// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 311: Ashen Oath Burn Component

#include "AshenOathBurnComponent.h"
#include "AshenOath_HealthComponent.h"

UAshenOathBurnComponent::UAshenOathBurnComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	MaxHealthBurnPenalty = 25.0f;
	bIsOathBurnActive = false;
}

void UAshenOathBurnComponent::BeginPlay()
{
	Super::BeginPlay();
}

bool UAshenOathBurnComponent::TriggerOathBurn()
{
	bIsOathBurnActive = true;

	if (AActor* Owner = GetOwner())
	{
		UAshenOath_HealthComponent* HealthComp = Owner->FindComponentByClass<UAshenOath_HealthComponent>();
		if (HealthComp)
		{
			HealthComp->ReceiveDamage(MaxHealthBurnPenalty, Owner);
		}
	}

	OnOathBurnActivated.Broadcast(2.5f, MaxHealthBurnPenalty);

	UE_LOG(LogTemp, Warning, TEXT("UAshenOathBurnComponent: OATH BURN ACTIVATED — 2.5x Damage Surge (+%.0f Max HP Burn Penalty)."),
		MaxHealthBurnPenalty);

	return true;
}
