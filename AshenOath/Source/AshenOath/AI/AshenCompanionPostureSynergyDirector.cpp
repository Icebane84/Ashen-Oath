// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AI/AshenCompanionPostureSynergyDirector.h"

UAshenCompanionPostureSynergyDirector::UAshenCompanionPostureSynergyDirector()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenCompanionPostureSynergyDirector::BeginPlay()
{
	Super::BeginPlay();
}

bool UAshenCompanionPostureSynergyDirector::SynchronizePostureSynergyFormation(AActor* LeaderActor, AActor* CompanionGarrett, AActor* CompanionSerafina)
{
	if (!LeaderActor || !CompanionGarrett || !CompanionSerafina) return false;
	bPostureSynergyActive = true;
	UE_LOG(LogTemp, Log, TEXT("UAshenCompanionPostureSynergyDirector: 3-character posture stance synergy formation synchronized."));
	return bPostureSynergyActive;
}
