// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Soul/AshenSoulConstellationNodeComponent.h"

UAshenSoulConstellationNodeComponent::UAshenSoulConstellationNodeComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CompanionNodeDistanceUnits = 250.0f;
}
void UAshenSoulConstellationNodeComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenSoulConstellationNodeComponent::UpdateConstellationDistances(ECompiledRelationalStance Stance)
{
	switch (Stance)
	{
	case ECompiledRelationalStance::MartyrStance:
		CompanionNodeDistanceUnits = 500.0f; // Distant nodes
		break;
	case ECompiledRelationalStance::WeaverStance:
		CompanionNodeDistanceUnits = 150.0f; // Intimate, bonded nodes
		break;
	case ECompiledRelationalStance::PredatorStance:
		CompanionNodeDistanceUnits = 350.0f; // Pragmatic combat spacing
		break;
	}

	UE_LOG(LogTemp, Log, TEXT("UAshenSoulConstellationNodeComponent: Constellation Node Distance: %.1fuu (Stance: %d)"),
		CompanionNodeDistanceUnits, static_cast<int32>(Stance));
}
