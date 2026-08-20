// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 772: Ashen Blackwood Bridge Gate Visual Locus Actor

#include "AshenBlackwoodBridgeGateVisualLocusActor.h"

AAshenBlackwoodBridgeGateVisualLocusActor::AAshenBlackwoodBridgeGateVisualLocusActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsGateOpen = false;
}

void AAshenBlackwoodBridgeGateVisualLocusActor::SetGateState(bool bOpen)
{
	bIsGateOpen = bOpen;
	const float Angle = bIsGateOpen ? 90.0f : 0.0f;

	OnGateUpdated.Broadcast(bIsGateOpen, Angle);

	UE_LOG(LogTemp, Warning, TEXT("AAshenBlackwoodBridgeGateVisualLocusActor: BRIDGE GATE STATE UPDATED -> Open: %s | Angle: %.0f deg."),
		bIsGateOpen ? TEXT("TRUE") : TEXT("FALSE"), Angle);
}
