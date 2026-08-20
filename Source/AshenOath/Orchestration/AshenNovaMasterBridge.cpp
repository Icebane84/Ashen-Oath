// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Orchestration/AshenNovaMasterBridge.h"

UAshenNovaMasterBridge::UAshenNovaMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenNovaMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	bNovaBridgeActive = true;
}

void UAshenNovaMasterBridge::BroadcastNovaTriggered(float MutualTrust, float NovaDamage)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenNovaMasterBridge: Broadcasted Nova Finisher Triggered (Trust: %.2f, Damage: %.1f)."),
		MutualTrust, NovaDamage);
}

void UAshenNovaMasterBridge::BroadcastSubsystemsInvalidated()
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenNovaMasterBridge: Broadcasted Subsystem Invalidation Pulse."));
}
