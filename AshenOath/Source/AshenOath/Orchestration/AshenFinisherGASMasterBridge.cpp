// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Orchestration/AshenFinisherGASMasterBridge.h"

UAshenFinisherGASMasterBridge::UAshenFinisherGASMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenFinisherGASMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	bFinisherGASBridgeActive = true;
}

void UAshenFinisherGASMasterBridge::BroadcastCharacterFinisherPulse(FName AbilityName, AActor* PrimaryCharacter, AActor* PartnerCharacter, AActor* TargetEnemy)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenFinisherGASMasterBridge: Broadcasted Finisher '%s' execution (Primary: %s, Partner: %s, Target: %s)."),
		*AbilityName.ToString(), PrimaryCharacter ? *PrimaryCharacter->GetName() : TEXT("None"),
		PartnerCharacter ? *PartnerCharacter->GetName() : TEXT("None"), TargetEnemy ? *TargetEnemy->GetName() : TEXT("None"));
}
