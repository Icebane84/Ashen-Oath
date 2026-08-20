// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenBossMemoryDuelVisualLocusActor.h"

AAshenBossMemoryDuelVisualLocusActor::AAshenBossMemoryDuelVisualLocusActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenBossMemoryDuelVisualLocusActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenBossMemoryDuelVisualLocusActor: Boss memory duel visual locus initialized."));
}

void AAshenBossMemoryDuelVisualLocusActor::TriggerRadialMemoryBeams()
{
	UE_LOG(LogTemp, Warning, TEXT("AAshenBossMemoryDuelVisualLocusActor: Radial golden memory beams casted across arena!"));
}
