// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenSomaticPostureAlignmentComponent.h"

UAshenSomaticPostureAlignmentComponent::UAshenSomaticPostureAlignmentComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSomaticPostureAlignmentComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenSomaticPostureAlignmentComponent::AlignSomaticPostureWithSoulState(float SoulStabilityScalar)
{
	PostureStabilityWeight = FMath::Clamp(SoulStabilityScalar, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenSomaticPostureAlignmentComponent: Somatic posture weight aligned to %f"), PostureStabilityWeight);
}
