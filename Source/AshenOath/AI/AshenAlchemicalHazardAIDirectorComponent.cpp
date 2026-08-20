// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "AI/AshenAlchemicalHazardAIDirectorComponent.h"

UAshenAlchemicalHazardAIDirectorComponent::UAshenAlchemicalHazardAIDirectorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenAlchemicalHazardAIDirectorComponent::BeginPlay() { Super::BeginPlay(); }

bool UAshenAlchemicalHazardAIDirectorComponent::ShouldEvadeHazardLocation(const FVector& EnemyLocation, const FVector& HazardLocation, float HazardRadius) const
{
	const float Distance = FVector::Dist(EnemyLocation, HazardLocation);
	const bool bShouldEvade = Distance <= HazardRadius;

	if (bShouldEvade)
	{
		UE_LOG(LogTemp, Log, TEXT("UAshenAlchemicalHazardAIDirectorComponent: Enemy detected alchemical hazard within %.1fuu -> Path rerouting."), Distance);
	}

	return bShouldEvade;
}
