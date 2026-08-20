// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AI/AshenRelationalPincerFormationDirector.h"

UAshenRelationalPincerFormationDirector::UAshenRelationalPincerFormationDirector()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenRelationalPincerFormationDirector::BeginPlay()
{
	Super::BeginPlay();
}

bool UAshenRelationalPincerFormationDirector::CoordinatePincerFormation(AActor* TargetLeader, AActor* CompanionGarrett, AActor* CompanionSerafina)
{
	if (!TargetLeader || !CompanionGarrett || !CompanionSerafina) return false;
	bPincerFormationActive = true;
	UE_LOG(LogTemp, Log, TEXT("UAshenRelationalPincerFormationDirector: Coordinated tactical pincer formation around leader %s"), *TargetLeader->GetName());
	return bPincerFormationActive;
}
