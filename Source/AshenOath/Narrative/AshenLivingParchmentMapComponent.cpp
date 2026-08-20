// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenLivingParchmentMapComponent.h"

UAshenLivingParchmentMapComponent::UAshenLivingParchmentMapComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	MinBreadcrumbDistance = 300.0f;
}
void UAshenLivingParchmentMapComponent::BeginPlay() { Super::BeginPlay(); }

bool UAshenLivingParchmentMapComponent::RecordPlayerPosition(FVector CurrentLocation)
{
	if (BreadcrumbPath.Num() > 0)
	{
		const float Dist = FVector::Dist(BreadcrumbPath.Last(), CurrentLocation);
		if (Dist < MinBreadcrumbDistance)
		{
			return false;
		}
	}

	BreadcrumbPath.Add(CurrentLocation);
	UE_LOG(LogTemp, Log, TEXT("UAshenLivingParchmentMapComponent: Recorded Breadcrumb Node #%d at %s"),
		BreadcrumbPath.Num(), *CurrentLocation.ToString());
	return true;
}
