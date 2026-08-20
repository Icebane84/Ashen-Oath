// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 325: Ashen Martyr's Tithe Component

#include "AshenMartyrsTitheComponent.h"
#include "AshenOath_HealthComponent.h"

UAshenMartyrsTitheComponent::UAshenMartyrsTitheComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	TotalSacrificedHealth = 0.0f;
}

void UAshenMartyrsTitheComponent::BeginPlay()
{
	Super::BeginPlay();
}

bool UAshenMartyrsTitheComponent::PerformMartyrSacrifice(float SacrificedMaxHealthAmount)
{
	if (SacrificedMaxHealthAmount <= 0.0f) return false;

	if (AActor* Owner = GetOwner())
	{
		UAshenOath_HealthComponent* HealthComp = Owner->FindComponentByClass<UAshenOath_HealthComponent>();
		if (HealthComp)
		{
			HealthComp->ReceiveDamage(SacrificedMaxHealthAmount, Owner);
		}
	}

	TotalSacrificedHealth += SacrificedMaxHealthAmount;
	const float BuffMultiplier = 1.0f + (TotalSacrificedHealth / 100.0f) * 0.25f; // +25% buff per 100 HP tithed

	OnMartyrTitheSacrificed.Broadcast(SacrificedMaxHealthAmount, BuffMultiplier);

	UE_LOG(LogTemp, Warning, TEXT("UAshenMartyrsTitheComponent: MARTYR TITHE SACRIFICED (-%.0f Max HP) -> Party Buff Multiplier: %.2fx."),
		SacrificedMaxHealthAmount, BuffMultiplier);

	return true;
}
