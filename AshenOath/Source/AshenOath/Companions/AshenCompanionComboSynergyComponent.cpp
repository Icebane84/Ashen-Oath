// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 206: Ashen Companion Combo Synergy Component

#include "AshenCompanionComboSynergyComponent.h"

UAshenCompanionComboSynergyComponent::UAshenCompanionComboSynergyComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	MaxSynergyMeter = 100.0f;
	SurgeMultiplier = 1.5f;
	CurrentSynergyMeter = 0.0f;
	CurrentMultiplier = 1.0f;
	bSurgeActive = false;
}

void UAshenCompanionComboSynergyComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenCompanionComboSynergyComponent::RegisterCompanionHit(float SynergyPoints)
{
	if (bSurgeActive) return;

	CurrentSynergyMeter = FMath::Clamp(CurrentSynergyMeter + SynergyPoints, 0.0f, MaxSynergyMeter);
	CurrentMultiplier = 1.0f + (CurrentSynergyMeter / MaxSynergyMeter) * 0.25f; // 1.0x to 1.25x scaling

	OnSynergyMeterChanged.Broadcast(CurrentSynergyMeter, CurrentMultiplier);

	UE_LOG(LogTemp, Log, TEXT("UAshenCompanionComboSynergyComponent: Synergy meter %.1f/%.1f (Multiplier: %.2fx)."),
		CurrentSynergyMeter, MaxSynergyMeter, CurrentMultiplier);
}

bool UAshenCompanionComboSynergyComponent::TriggerSynergySurge()
{
	if (CurrentSynergyMeter < MaxSynergyMeter || bSurgeActive) return false;

	bSurgeActive = true;
	CurrentMultiplier = SurgeMultiplier;
	CurrentSynergyMeter = 0.0f;

	OnSynergySurgeTriggered.Broadcast(SurgeMultiplier);
	OnSynergyMeterChanged.Broadcast(CurrentSynergyMeter, CurrentMultiplier);

	UE_LOG(LogTemp, Warning, TEXT("UAshenCompanionComboSynergyComponent: SYNERGY SURGE TRIGGERED — %.2fx multiplier active!"), SurgeMultiplier);
	return true;
}
