// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenSunderedMemoryBridgeActor.h"

AAshenSunderedMemoryBridgeActor::AAshenSunderedMemoryBridgeActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsBridgeSolidified = false;
}
void AAshenSunderedMemoryBridgeActor::BeginPlay() { Super::BeginPlay(); }

void AAshenSunderedMemoryBridgeActor::SetBridgeReconstructed(bool bReconstructed)
{
	bIsBridgeSolidified = bReconstructed;
	UE_LOG(LogTemp, Warning, TEXT("AAshenSunderedMemoryBridgeActor: Bridge '%s' state set to Solidified: %s."),
		*BridgeID.ToString(), bIsBridgeSolidified ? TEXT("TRUE") : TEXT("FALSE"));
}
