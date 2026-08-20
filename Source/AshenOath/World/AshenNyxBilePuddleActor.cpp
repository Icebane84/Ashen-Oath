// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenNyxBilePuddleActor.h"

AAshenNyxBilePuddleActor::AAshenNyxBilePuddleActor()
{
	PrimaryActorTick.bCanEverTick = false;
	PuddleRadius = 150.0f;
	SlowFactor = 0.65f;
	RemainingDuration = 8.0f;
}
void AAshenNyxBilePuddleActor::BeginPlay() { Super::BeginPlay(); }

bool AAshenNyxBilePuddleActor::ApplyPuddleSlow(AActor* TargetActor)
{
	if (!TargetActor) return false;
	UE_LOG(LogTemp, Warning, TEXT("AAshenNyxBilePuddleActor: Applied Bile Slow (%.2fx speed) to %s."),
		SlowFactor, *TargetActor->GetName());
	return true;
}
