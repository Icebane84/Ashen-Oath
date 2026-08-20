// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/AshenGarrettFlankDistractionAdapterComponent.h"

UAshenGarrettFlankDistractionAdapterComponent::UAshenGarrettFlankDistractionAdapterComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenGarrettFlankDistractionAdapterComponent::BeginPlay()
{
	Super::BeginPlay();
}

bool UAshenGarrettFlankDistractionAdapterComponent::ExecuteFlankDistractionManeuver(AActor* TargetEnemy)
{
	if (!TargetEnemy) return false;
	UE_LOG(LogTemp, Log, TEXT("UAshenGarrettFlankDistractionAdapterComponent: Garrett executed flank distraction maneuver against target %s"), *TargetEnemy->GetName());
	return true;
}
