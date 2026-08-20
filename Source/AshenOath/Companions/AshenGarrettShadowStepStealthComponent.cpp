// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 701: Ashen Garrett Shadow Step Stealth Component

#include "AshenGarrettShadowStepStealthComponent.h"

UAshenGarrettShadowStepStealthComponent::UAshenGarrettShadowStepStealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	bIsStealthed = false;
}

void UAshenGarrettShadowStepStealthComponent::ExecuteShadowStep(FVector TargetStealthPosition)
{
	bIsStealthed = true;
	const bool bDropped = true; // Threat completely dropped
	OnShadowStepExecuted.Broadcast(TargetStealthPosition, bDropped);

	UE_LOG(LogTemp, Warning, TEXT("UAshenGarrettShadowStepStealthComponent: SHADOW STEP EXECUTED -> Relocated to (%s) | Threat Dropped: TRUE."),
		*TargetStealthPosition.ToString());
}
