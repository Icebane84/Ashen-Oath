// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenMiasmaExposureComponent.h"

UAshenMiasmaExposureComponent::UAshenMiasmaExposureComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	FilterIntegrity = 1.0f;
	FilterDegradationRate = 0.05f;
	BaseToxicityDamagePerSecond = 12.0f;
}
void UAshenMiasmaExposureComponent::BeginPlay() { Super::BeginPlay(); }

float UAshenMiasmaExposureComponent::CalculateExposureDamage(float DeltaSeconds, float AtmosphericToxicity)
{
	if (AtmosphericToxicity <= 0.20f)
	{
		return 0.0f; // Safe baseline
	}

	// Degrade filter while in toxic atmosphere
	if (FilterIntegrity > 0.0f)
	{
		FilterIntegrity = FMath::Max(0.0f, FilterIntegrity - (FilterDegradationRate * DeltaSeconds * AtmosphericToxicity));
	}

	// Unfiltered damage multiplier: 1.0x when Filter is 0.0, down to 0.1x when Filter is 1.0
	const float FilterProtection = FilterIntegrity * 0.90f; // Blocks up to 90%
	const float DamageRatio = 1.0f - FilterProtection;

	const float TickDamage = BaseToxicityDamagePerSecond * AtmosphericToxicity * DamageRatio * DeltaSeconds;

	UE_LOG(LogTemp, Log, TEXT("UAshenMiasmaExposureComponent: Tick Damage: %.2f (Filter: %.1f%%, Toxicity: %.2f)"),
		TickDamage, FilterIntegrity * 100.0f, AtmosphericToxicity);

	return TickDamage;
}

void UAshenMiasmaExposureComponent::RestoreFilter(float Amount)
{
	FilterIntegrity = FMath::Clamp(FilterIntegrity + Amount, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenMiasmaExposureComponent: Filter restored to %.1f%%."), FilterIntegrity * 100.0f);
}
