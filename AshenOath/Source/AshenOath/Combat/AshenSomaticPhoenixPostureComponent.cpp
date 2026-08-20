// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenSomaticPhoenixPostureComponent.h"

UAshenSomaticPhoenixPostureComponent::UAshenSomaticPhoenixPostureComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSomaticPhoenixPostureComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenSomaticPhoenixPostureComponent::AlignPhoenixPostureStance()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenSomaticPhoenixPostureComponent: Somatic stance aligned to Sovereign Phoenix posture (Scalar: %f)."), PhoenixStanceAlignmentScalar);
}
