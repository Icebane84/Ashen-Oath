// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Player/AshenTraversalMovementEnhancerComponent.h"

UAshenTraversalMovementEnhancerComponent::UAshenTraversalMovementEnhancerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	BaseSprintSpeed = 600.0f;
}
void UAshenTraversalMovementEnhancerComponent::BeginPlay() { Super::BeginPlay(); }

float UAshenTraversalMovementEnhancerComponent::CalculateAdjustedSprintSpeed(float WindResistanceFactor, bool bAetherDashActive) const
{
	if (bAetherDashActive)
	{
		return BaseSprintSpeed * 2.2f; // Dash surge
	}

	const float Resistance = FMath::Clamp(WindResistanceFactor, 0.0f, 0.50f);
	const float FinalSpeed = BaseSprintSpeed * (1.0f - Resistance);

	UE_LOG(LogTemp, Log, TEXT("UAshenTraversalMovementEnhancerComponent: Calculated Sprint Speed: %.1f uu/s (Resistance: %.2f)"),
		FinalSpeed, Resistance);

	return FinalSpeed;
}
