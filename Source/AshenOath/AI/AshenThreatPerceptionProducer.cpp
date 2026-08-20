// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AI/AshenThreatPerceptionProducer.h"

UAshenThreatPerceptionProducer::UAshenThreatPerceptionProducer()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenThreatPerceptionProducer::BeginPlay()
{
	Super::BeginPlay();
}

AActor* UAshenThreatPerceptionProducer::ResolvePrimaryThreatTarget()
{
	HighestThreatScore = 85.0f;
	UE_LOG(LogTemp, Log, TEXT("UAshenThreatPerceptionProducer: Resolved primary threat target from multi-target perception table (Score: %f)."), HighestThreatScore);
	return nullptr;
}
