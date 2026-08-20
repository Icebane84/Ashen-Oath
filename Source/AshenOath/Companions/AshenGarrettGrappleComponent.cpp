// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Companions/AshenGarrettGrappleComponent.h"

UAshenGarrettGrappleComponent::UAshenGarrettGrappleComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenGarrettGrappleComponent::BeginPlay() { Super::BeginPlay(); }

bool UAshenGarrettGrappleComponent::FireGrapple(FVector TargetLocation, bool bIsCompanionInterpose)
{
	bIsGrappling = true;
	CurrentGrappleState = bIsCompanionInterpose ? EAshenGrappleState::Interposing : EAshenGrappleState::Firing;
	if (OnGrappleFired.IsBound())
	{
		OnGrappleFired.Broadcast(TargetLocation, CurrentGrappleState);
	}
	UE_LOG(LogTemp, Warning, TEXT("UAshenGarrettGrappleComponent: Grapple hook launched towards (%f, %f, %f) | Interpose: %s"),
		TargetLocation.X, TargetLocation.Y, TargetLocation.Z, bIsCompanionInterpose ? TEXT("YES") : TEXT("NO"));
	return true;
}

bool UAshenGarrettGrappleComponent::LaunchGrapplingHook(FVector TargetLocation)
{
	return FireGrapple(TargetLocation, false);
}
