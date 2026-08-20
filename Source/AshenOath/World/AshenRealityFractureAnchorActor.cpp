// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenRealityFractureAnchorActor.h"

AAshenRealityFractureAnchorActor::AAshenRealityFractureAnchorActor()
{
	PrimaryActorTick.bCanEverTick = false;
	StabilizationRadius = 1200.0f;
	bIsAnchorStabilized = false;
}
void AAshenRealityFractureAnchorActor::BeginPlay() { Super::BeginPlay(); }

bool AAshenRealityFractureAnchorActor::ConsecrateAnchor(AActor* InstigatingPlayer)
{
	if (!InstigatingPlayer) return false;
	bIsAnchorStabilized = true;
	UE_LOG(LogTemp, Warning, TEXT("AAshenRealityFractureAnchorActor: Reality Fracture Anchor consecrated (Stabilization Radius: %.1fuu)!"),
		StabilizationRadius);
	return true;
}
