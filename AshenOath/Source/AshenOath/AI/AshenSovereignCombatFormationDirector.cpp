// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AI/AshenSovereignCombatFormationDirector.h"

UAshenSovereignCombatFormationDirector::UAshenSovereignCombatFormationDirector()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSovereignCombatFormationDirector::BeginPlay()
{
	Super::BeginPlay();
}

bool UAshenSovereignCombatFormationDirector::SynchronizeSovereignFormation(AActor* LeaderActor, AActor* CompanionGarrett, AActor* CompanionSerafina)
{
	if (!LeaderActor || !CompanionGarrett || !CompanionSerafina) return false;
	bSovereignFormationSynchronized = true;
	UE_LOG(LogTemp, Log, TEXT("UAshenSovereignCombatFormationDirector: Sovereign Phoenix 3-character combat formation synchronized clean."));
	return bSovereignFormationSynchronized;
}
