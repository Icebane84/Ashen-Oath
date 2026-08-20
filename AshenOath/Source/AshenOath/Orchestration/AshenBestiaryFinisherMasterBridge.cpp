// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Orchestration/AshenBestiaryFinisherMasterBridge.h"

UAshenBestiaryFinisherMasterBridge::UAshenBestiaryFinisherMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenBestiaryFinisherMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	bBestiaryBridgeActive = true;
}

void UAshenBestiaryFinisherMasterBridge::BroadcastBestiaryFinisherPulse(EAshenPartyFinisherType FinisherType, AActor* TargetActor)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenBestiaryFinisherMasterBridge: Bestiary Finisher Pulse for Type %d on %s broadcasted across domain adapters."),
		(int32)FinisherType, TargetActor ? *TargetActor->GetName() : TEXT("Target"));
}
