// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "AI/AshenSkeletalSightTracingAIDirectorComponent.h"

UAshenSkeletalSightTracingAIDirectorComponent::UAshenSkeletalSightTracingAIDirectorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	HeadSocketName = FName(TEXT("head"));
}
void UAshenSkeletalSightTracingAIDirectorComponent::BeginPlay() { Super::BeginPlay(); }

float UAshenSkeletalSightTracingAIDirectorComponent::CalculateEffectiveVisionConeAngle(bool bIsHunchedGuarded) const
{
	// Normal posture: 120 degree cone. Hunched/guarded posture: contracts to 70 degree cone
	return bIsHunchedGuarded ? 70.0f : 120.0f;
}
