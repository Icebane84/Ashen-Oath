// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "AI/AshenCartographerAIDirectorComponent.h"

UAshenCartographerAIDirectorComponent::UAshenCartographerAIDirectorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenCartographerAIDirectorComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenCartographerAIDirectorComponent::NotifyNearbyUnmappedLandmark(FVector LandmarkLocation, FString LandmarkName)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenCartographerAIDirectorComponent: Companion calls out unmapped landmark: \"%s\" at %s!"),
		*LandmarkName, *LandmarkLocation.ToString());
}
