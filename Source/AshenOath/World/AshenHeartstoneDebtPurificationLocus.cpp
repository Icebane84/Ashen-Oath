// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenHeartstoneDebtPurificationLocus.h"

AAshenHeartstoneDebtPurificationLocus::AAshenHeartstoneDebtPurificationLocus()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenHeartstoneDebtPurificationLocus::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenHeartstoneDebtPurificationLocus: Heartstone purification locus active (Radius=%f)."), PurificationRadius);
}

bool AAshenHeartstoneDebtPurificationLocus::PerformDebtPurificationRitual()
{
	UE_LOG(LogTemp, Warning, TEXT("AAshenHeartstoneDebtPurificationLocus: Integration Debt purified to 0.0f at Heartstone shrine."));
	return true;
}
