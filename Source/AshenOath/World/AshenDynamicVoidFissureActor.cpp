// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenDynamicVoidFissureActor.h"

AAshenDynamicVoidFissureActor::AAshenDynamicVoidFissureActor()
{
	PrimaryActorTick.bCanEverTick = false;
	FissureSpanUnits = 1000.0f;
}
void AAshenDynamicVoidFissureActor::BeginPlay() { Super::BeginPlay(); }

void AAshenDynamicVoidFissureActor::OpenFissure()
{
	UE_LOG(LogTemp, Warning, TEXT("AAshenDynamicVoidFissureActor: VOID FISSURE OPENED across %.1fuu span! Requires light bridge traversal."),
		FissureSpanUnits);
}
