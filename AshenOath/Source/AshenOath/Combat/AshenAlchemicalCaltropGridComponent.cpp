// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenAlchemicalCaltropGridComponent.h"

UAshenAlchemicalCaltropGridComponent::UAshenAlchemicalCaltropGridComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	ActiveCaltropFieldsCount = 0;
}
void UAshenAlchemicalCaltropGridComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenAlchemicalCaltropGridComponent::RegisterCaltropFieldSpawned()
{
	ActiveCaltropFieldsCount++;
	UE_LOG(LogTemp, Log, TEXT("UAshenAlchemicalCaltropGridComponent: Caltrop Field Registered (Total Active: %d) -> Channeling AI pathfinding!"),
		ActiveCaltropFieldsCount);
}
