// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenInnerWorldMemorySanctuaryTouchstoneActor.h"

AAshenInnerWorldMemorySanctuaryTouchstoneActor::AAshenInnerWorldMemorySanctuaryTouchstoneActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenInnerWorldMemorySanctuaryTouchstoneActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenInnerWorldMemorySanctuaryTouchstoneActor: Touchstone Actor initialized."));
}

bool AAshenInnerWorldMemorySanctuaryTouchstoneActor::InitiateInnerWorldMeditation()
{
	UE_LOG(LogTemp, Warning, TEXT("AAshenInnerWorldMemorySanctuaryTouchstoneActor: Initiated meditation entering Inner World of Oathbringer."));
	return true;
}
