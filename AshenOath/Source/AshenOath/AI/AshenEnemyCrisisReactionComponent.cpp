// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AI/AshenEnemyCrisisReactionComponent.h"

UAshenEnemyCrisisReactionComponent::UAshenEnemyCrisisReactionComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenEnemyCrisisReactionComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenEnemyCrisisReactionComponent::TriggerPredatoryRecoilPanic()
{
	bInRecoilPanicState = true;
	UE_LOG(LogTemp, Log, TEXT("UAshenEnemyCrisisReactionComponent: AI entered Predatory Recoil & Panic State (Path A)."));
}

void UAshenEnemyCrisisReactionComponent::TriggerMomentumShatterOvercommitment()
{
	bInRecoilPanicState = false;
	UE_LOG(LogTemp, Log, TEXT("UAshenEnemyCrisisReactionComponent: AI entered Momentum Shatter Overcommitment Phase (Path B)."));
}
