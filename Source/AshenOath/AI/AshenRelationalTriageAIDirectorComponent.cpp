// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "AI/AshenRelationalTriageAIDirectorComponent.h"

UAshenRelationalTriageAIDirectorComponent::UAshenRelationalTriageAIDirectorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CompanionProximitySpacingUnits = 250.0f;
}
void UAshenRelationalTriageAIDirectorComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenRelationalTriageAIDirectorComponent::ApplyRelationalStanceToAI(ECompiledRelationalStance Stance)
{
	switch (Stance)
	{
	case ECompiledRelationalStance::MartyrStance:
		CompanionProximitySpacingUnits = 500.0f; // Distant, hesitant AI support
		break;
	case ECompiledRelationalStance::WeaverStance:
		CompanionProximitySpacingUnits = 150.0f; // Tight, instinctive co-op
		break;
	case ECompiledRelationalStance::PredatorStance:
		CompanionProximitySpacingUnits = 350.0f; // Pragmatic combat spacing
		break;
	}

	UE_LOG(LogTemp, Log, TEXT("UAshenRelationalTriageAIDirectorComponent: AI Spacing set to %.1fuu (Stance: %d)"),
		CompanionProximitySpacingUnits, static_cast<int32>(Stance));
}
