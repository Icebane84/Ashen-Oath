// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 278: Ashen Boss Health Bar Controller Component

#include "AshenBossHealthBarControllerComponent.h"

UAshenBossHealthBarControllerComponent::UAshenBossHealthBarControllerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	BossDisplayName = FName("Greywatch Shroud-Knight");
}

void UAshenBossHealthBarControllerComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenBossHealthBarControllerComponent::UpdateBossHealth(float CurrentHealth, float MaxHealth, int32 CurrentPhase)
{
	if (MaxHealth <= 0.0f) return;

	const float HealthPct = FMath::Clamp(CurrentHealth / MaxHealth, 0.0f, 1.0f);
	OnBossHealthBarUpdated.Broadcast(HealthPct, CurrentPhase, BossDisplayName);

	UE_LOG(LogTemp, Log, TEXT("UAshenBossHealthBarControllerComponent: Boss '%s' Phase %d Health: %.1f%%."),
		*BossDisplayName.ToString(), CurrentPhase, HealthPct * 100.0f);
}
