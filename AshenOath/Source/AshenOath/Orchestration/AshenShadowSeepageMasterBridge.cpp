// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Orchestration/AshenShadowSeepageMasterBridge.h"

UAshenShadowSeepageMasterBridge::UAshenShadowSeepageMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenShadowSeepageMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	bSeepageBridgeActive = true;
}

void UAshenShadowSeepageMasterBridge::BroadcastSeepagePhaseChanged(EShadowSeepagePhase NewPhase, float CorruptionScalar)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenShadowSeepageMasterBridge: Broadcasted Seepage Phase Changed -> Phase: %d, Corruption: %.2f"),
		static_cast<int32>(NewPhase), CorruptionScalar);
}

void UAshenShadowSeepageMasterBridge::BroadcastBilePuddleSpawned(const FVector& PuddleLocation)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenShadowSeepageMasterBridge: Broadcasted Nyx Bile Puddle Spawned at %s."), *PuddleLocation.ToString());
}
