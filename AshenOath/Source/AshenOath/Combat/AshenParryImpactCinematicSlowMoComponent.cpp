// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenParryImpactCinematicSlowMoComponent.h"

UAshenParryImpactCinematicSlowMoComponent::UAshenParryImpactCinematicSlowMoComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenParryImpactCinematicSlowMoComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenParryImpactCinematicSlowMoComponent::TriggerParrySlowMo()
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenParryImpactCinematicSlowMoComponent: Parry impact slow-mo activated: %.2fx for %.2fs."), DilationFactor, Duration);
}
