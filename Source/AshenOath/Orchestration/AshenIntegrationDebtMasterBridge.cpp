// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Orchestration/AshenIntegrationDebtMasterBridge.h"

UAshenIntegrationDebtMasterBridge::UAshenIntegrationDebtMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenIntegrationDebtMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	bDebtBridgeActive = true;
}

void UAshenIntegrationDebtMasterBridge::BroadcastDebtEscalationPulse(EAshenIntegrationDebtStage Stage)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenIntegrationDebtMasterBridge: Integration Debt escalation pulse broadcasted across all domain adapters for stage %d."), (int32)Stage);
}
