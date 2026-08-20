// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Crafting/AshenCampfireRestManagerComponent.h"

UAshenCampfireRestManagerComponent::UAshenCampfireRestManagerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	bIsRestingAtCampfire = false;
}
void UAshenCampfireRestManagerComponent::BeginPlay() { Super::BeginPlay(); }

bool UAshenCampfireRestManagerComponent::BeginCampfireRest()
{
	bIsRestingAtCampfire = true;
	UE_LOG(LogTemp, Warning, TEXT("UAshenCampfireRestManagerComponent: Began Campfire Rest Phase. Workstation active."));
	return true;
}

void UAshenCampfireRestManagerComponent::EndCampfireRest()
{
	bIsRestingAtCampfire = false;
	UE_LOG(LogTemp, Log, TEXT("UAshenCampfireRestManagerComponent: Ended Campfire Rest Phase. Returning to traversal."));
}
