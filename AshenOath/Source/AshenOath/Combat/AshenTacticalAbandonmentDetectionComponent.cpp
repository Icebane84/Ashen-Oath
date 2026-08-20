// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenTacticalAbandonmentDetectionComponent.h"

UAshenTacticalAbandonmentDetectionComponent::UAshenTacticalAbandonmentDetectionComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenTacticalAbandonmentDetectionComponent::BeginPlay() { Super::BeginPlay(); }

bool UAshenTacticalAbandonmentDetectionComponent::CheckTacticalAbandonmentCondition(FName CompanionID, FVector CompanionLocation, FVector PlayerLocation, int32 SurroundingEnemyCount)
{
	const float Distance = FVector::Dist(CompanionLocation, PlayerLocation);
	if (Distance >= AbandonmentDistanceThreshold && SurroundingEnemyCount >= 2)
	{
		if (OnAbandonmentDetected.IsBound())
		{
			OnAbandonmentDetected.Broadcast(CompanionID);
		}
		UE_LOG(LogTemp, Warning, TEXT("UAshenTacticalAbandonmentDetectionComponent: Tactical abandonment detected for %s (Dist: %.1fuu, Enemies: %d)"),
			*CompanionID.ToString(), Distance, SurroundingEnemyCount);
		return true;
	}
	return false;
}
