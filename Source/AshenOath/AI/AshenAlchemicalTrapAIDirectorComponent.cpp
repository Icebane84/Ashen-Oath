// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "AI/AshenAlchemicalTrapAIDirectorComponent.h"

UAshenAlchemicalTrapAIDirectorComponent::UAshenAlchemicalTrapAIDirectorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenAlchemicalTrapAIDirectorComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenAlchemicalTrapAIDirectorComponent::DirectProactiveTrapPlacement(FVector ChokePointLocation)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenAlchemicalTrapAIDirectorComponent: Directing Garrett to seed caltrops and tripwires at choke point %s!"),
		*ChokePointLocation.ToString());
}
