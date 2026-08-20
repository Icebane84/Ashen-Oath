// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenSomaticPostureControllerComponent.h"

UAshenSomaticPostureControllerComponent::UAshenSomaticPostureControllerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSomaticPostureControllerComponent::UpdatePostureWeight(EStanceProfile Stance)
{
	switch (Stance)
	{
	case EStanceProfile::Hunched_Guarded:
		PostureBlendWeight = 1.0f;
		break;
	case EStanceProfile::Upright_Grounded:
		PostureBlendWeight = 0.0f;
		break;
	case EStanceProfile::Balanced_Steady:
	default:
		PostureBlendWeight = 0.5f;
		break;
	}

	UE_LOG(LogTemp, Log, TEXT("UAshenSomaticPostureControllerComponent: Posture blend weight updated to %.2f"), PostureBlendWeight);
}
