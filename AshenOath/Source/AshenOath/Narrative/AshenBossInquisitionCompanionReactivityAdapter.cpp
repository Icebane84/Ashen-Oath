// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenBossInquisitionCompanionReactivityAdapter.h"

UAshenBossInquisitionCompanionReactivityAdapter::UAshenBossInquisitionCompanionReactivityAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenBossInquisitionCompanionReactivityAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenBossInquisitionCompanionReactivityAdapter::TriggerCompanionBossReaction(FName CompanionID, uint8 BossPhaseIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenBossInquisitionCompanionReactivityAdapter: %s shouts tactical warning for Boss Phase %d!"),
		*CompanionID.ToString(), BossPhaseIndex);
}
