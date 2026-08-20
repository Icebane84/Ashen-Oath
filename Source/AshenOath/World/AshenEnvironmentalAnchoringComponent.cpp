// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 367: Ashen Environmental Anchoring Component

#include "AshenEnvironmentalAnchoringComponent.h"

UAshenEnvironmentalAnchoringComponent::UAshenEnvironmentalAnchoringComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	bIsAnchored = false;
}

void UAshenEnvironmentalAnchoringComponent::BeginPlay()
{
	Super::BeginPlay();
}

bool UAshenEnvironmentalAnchoringComponent::BindEnvironmentalAnchor()
{
	bIsAnchored = true;
	const float ReductionFactor = 0.50f;

	OnAnchorStateChanged.Broadcast(true, ReductionFactor);

	UE_LOG(LogTemp, Warning, TEXT("UAshenEnvironmentalAnchoringComponent: ENVIRONMENTAL ANCHOR BOUND — Local Corruption reduced by 50 percent."));

	return true;
}
