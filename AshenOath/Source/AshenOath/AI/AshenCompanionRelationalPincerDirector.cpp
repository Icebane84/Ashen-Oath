// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AI/AshenCompanionRelationalPincerDirector.h"

UAshenCompanionRelationalPincerDirector::UAshenCompanionRelationalPincerDirector()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenCompanionRelationalPincerDirector::BeginPlay()
{
	Super::BeginPlay();
}

bool UAshenCompanionRelationalPincerDirector::SynchronizeRelationalPincerFormation(AActor* LeaderActor, AActor* CompanionGarrett, AActor* CompanionSerafina)
{
	if (!LeaderActor || !CompanionGarrett || !CompanionSerafina) return false;
	bRelationalPincerActive = true;
	UE_LOG(LogTemp, Log, TEXT("UAshenCompanionRelationalPincerDirector: Companion relational pincer formation synchronized."));
	return bRelationalPincerActive;
}
