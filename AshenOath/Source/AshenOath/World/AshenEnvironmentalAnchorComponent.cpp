// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenEnvironmentalAnchorComponent.h"

UAshenEnvironmentalAnchorComponent::UAshenEnvironmentalAnchorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	PurificationRadius = 1200.0f;
	bIsAnchorConsecrated = false;
}
void UAshenEnvironmentalAnchorComponent::BeginPlay() { Super::BeginPlay(); }

bool UAshenEnvironmentalAnchorComponent::ConsecrateAnchor()
{
	bIsAnchorConsecrated = true;
	UE_LOG(LogTemp, Warning, TEXT("UAshenEnvironmentalAnchorComponent: Environmental Anchor consecrated! Purifying %.1f radius corruption zone."), PurificationRadius);
	return true;
}
