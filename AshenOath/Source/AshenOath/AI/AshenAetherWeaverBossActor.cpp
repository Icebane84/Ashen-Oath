// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "AI/AshenAetherWeaverBossActor.h"

AAshenAetherWeaverBossActor::AAshenAetherWeaverBossActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsCorporealLocked = false;
}
void AAshenAetherWeaverBossActor::BeginPlay() { Super::BeginPlay(); }

void AAshenAetherWeaverBossActor::LockIntoCorporealSpace()
{
	bIsCorporealLocked = true;
	UE_LOG(LogTemp, Warning, TEXT("AAshenAetherWeaverBossActor: AETHER-WEAVER LOCKED IN CORPOREAL SPACE! Phasing rhythms nullified!"));
}
