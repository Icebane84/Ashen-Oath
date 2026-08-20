// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenCognitiveAIArenaLocusActor.h"

AAshenCognitiveAIArenaLocusActor::AAshenCognitiveAIArenaLocusActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenCognitiveAIArenaLocusActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenCognitiveAIArenaLocusActor: Cognitive AI Arena Locus Actor initialized."));
}

bool AAshenCognitiveAIArenaLocusActor::IsTargetWithinArenaBounds(FVector TargetLocation) const
{
	return FVector::Dist(GetActorLocation(), TargetLocation) <= ArenaTacticalRadius;
}
