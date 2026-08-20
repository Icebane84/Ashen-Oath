// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Orchestration/AshenPartySyncFinisherMasterBridge.h"

UAshenPartySyncFinisherMasterBridge::UAshenPartySyncFinisherMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenPartySyncFinisherMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	bFinisherBridgeActive = true;
}

void UAshenPartySyncFinisherMasterBridge::BroadcastFinisherPulse(EAshenPartyFinisherType FinisherType, AActor* TargetActor)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenPartySyncFinisherMasterBridge: Finisher Event for Type %d on %s broadcasted across domain adapters."),
		(int32)FinisherType, TargetActor ? *TargetActor->GetName() : TEXT("Target"));
}
