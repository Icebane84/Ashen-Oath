// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AI/AshenCompanionMasterSynergyDirector.h"

UAshenCompanionMasterSynergyDirector::UAshenCompanionMasterSynergyDirector()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenCompanionMasterSynergyDirector::BeginPlay()
{
	Super::BeginPlay();
}

bool UAshenCompanionMasterSynergyDirector::SynchronizeMasterSynergyFormation(AActor* LeaderActor, AActor* CompanionGarrett, AActor* CompanionSerafina)
{
	if (!LeaderActor || !CompanionGarrett || !CompanionSerafina) return false;
	bMasterSynergyActive = true;
	UE_LOG(LogTemp, Log, TEXT("UAshenCompanionMasterSynergyDirector: 3-character companion master synergy formation synchronized."));
	return bMasterSynergyActive;
}
