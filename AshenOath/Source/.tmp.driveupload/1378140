// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenSomaticPostureStanceAlignmentComponent.h"

UAshenSomaticPostureStanceAlignmentComponent::UAshenSomaticPostureStanceAlignmentComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSomaticPostureStanceAlignmentComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenSomaticPostureStanceAlignmentComponent::UpdatePostureAlignment(float DeltaAlignment)
{
	PostureAlignmentScalar = FMath::Clamp(PostureAlignmentScalar + DeltaAlignment, 0.0f, 2.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenSomaticPostureStanceAlignmentComponent: Posture alignment scalar updated to %f"), PostureAlignmentScalar);
}
