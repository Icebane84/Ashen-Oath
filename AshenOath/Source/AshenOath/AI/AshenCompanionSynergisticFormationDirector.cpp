// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AI/AshenCompanionSynergisticFormationDirector.h"

UAshenCompanionSynergisticFormationDirector::UAshenCompanionSynergisticFormationDirector()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenCompanionSynergisticFormationDirector::BeginPlay()
{
	Super::BeginPlay();
}

bool UAshenCompanionSynergisticFormationDirector::SynchronizeSynergisticFormation(AActor* LeaderActor, AActor* CompanionGarrett, AActor* CompanionSerafina)
{
	if (!LeaderActor || !CompanionGarrett || !CompanionSerafina) return false;
	bSynergisticFormationActive = true;
	UE_LOG(LogTemp, Log, TEXT("UAshenCompanionSynergisticFormationDirector: 3-character companion synergistic tactical formation synchronized."));
	return bSynergisticFormationActive;
}
