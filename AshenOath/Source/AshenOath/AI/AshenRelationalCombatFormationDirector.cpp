// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AI/AshenRelationalCombatFormationDirector.h"

UAshenRelationalCombatFormationDirector::UAshenRelationalCombatFormationDirector()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenRelationalCombatFormationDirector::BeginPlay()
{
	Super::BeginPlay();
}

bool UAshenRelationalCombatFormationDirector::SynchronizeRelationalFormation(AActor* LeaderActor, AActor* CompanionGarrett, AActor* CompanionSerafina)
{
	if (!LeaderActor || !CompanionGarrett || !CompanionSerafina) return false;
	bRelationalFormationActive = true;
	UE_LOG(LogTemp, Log, TEXT("UAshenRelationalCombatFormationDirector: Relational 3-character combat formation synchronized."));
	return bRelationalFormationActive;
}
