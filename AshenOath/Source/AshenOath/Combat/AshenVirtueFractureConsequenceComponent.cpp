// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 516: Ashen Virtue Fracture Consequence Component

#include "AshenVirtueFractureConsequenceComponent.h"

UAshenVirtueFractureConsequenceComponent::UAshenVirtueFractureConsequenceComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	ActiveFractureTag = FName(TEXT("Fracture.SurvivorsGuilt"));
	GarrettConfidencePenalty = 0.0f;
}

void UAshenVirtueFractureConsequenceComponent::InflictVirtueFracture(FName FractureTag, float Severity)
{
	if (FractureTag.IsNone()) return;

	ActiveFractureTag = FractureTag;
	GarrettConfidencePenalty = FMath::Clamp(Severity * 15.0f, 0.0f, 50.0f);

	OnVirtueFractureInflicted.Broadcast(ActiveFractureTag, GarrettConfidencePenalty);

	UE_LOG(LogTemp, Error, TEXT("UAshenVirtueFractureConsequenceComponent: VIRTUE FRACTURE INFLICTED -> '%s' (Garrett Confidence Penalty: -%.1f%%)."),
		*ActiveFractureTag.ToString(), GarrettConfidencePenalty);
}
