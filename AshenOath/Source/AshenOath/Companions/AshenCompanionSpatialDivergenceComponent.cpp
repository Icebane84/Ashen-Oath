// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Companions/AshenCompanionSpatialDivergenceComponent.h"

UAshenCompanionSpatialDivergenceComponent::UAshenCompanionSpatialDivergenceComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenCompanionSpatialDivergenceComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenCompanionSpatialDivergenceComponent::RecalculateSpatialDivergenceOffsets(float GarrettTrust, float SerafinaTrust)
{
	// Garrett offset expands to 800uu under low trust (Cynical_Isolated / low trust)
	GarrettNavigationOffset  = FMath::Lerp(800.0f, 250.0f, GarrettTrust);
	// Serafina offset expands to 550uu under low trust (Burned_Out / low trust)
	SerafinaNavigationOffset = FMath::Lerp(550.0f, 200.0f, SerafinaTrust);

	UE_LOG(LogTemp, Log, TEXT("UAshenCompanionSpatialDivergenceComponent: Offsets recalculated — Garrett: %.1fuu, Serafina: %.1fuu"),
		GarrettNavigationOffset, SerafinaNavigationOffset);
}
