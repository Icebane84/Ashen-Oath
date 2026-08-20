// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenPhysicalTraumaLightBridgeActor.h"

AAshenPhysicalTraumaLightBridgeActor::AAshenPhysicalTraumaLightBridgeActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsNavmeshActive = false;
}
void AAshenPhysicalTraumaLightBridgeActor::BeginPlay() { Super::BeginPlay(); }

void AAshenPhysicalTraumaLightBridgeActor::SolidifyBridgeMesh()
{
	bIsNavmeshActive = true;
	UE_LOG(LogTemp, Warning, TEXT("AAshenPhysicalTraumaLightBridgeActor: TRAUMA LIGHT BRIDGE SOLIDIFIED! Navmesh active for trio traversal."));
}
