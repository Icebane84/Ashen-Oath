// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenProtectiveInterceptDecoyActor.h"

AAshenProtectiveInterceptDecoyActor::AAshenProtectiveInterceptDecoyActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bWasTargetShoved = false;
}
void AAshenProtectiveInterceptDecoyActor::BeginPlay() { Super::BeginPlay(); }

void AAshenProtectiveInterceptDecoyActor::ReceiveProtectiveShove()
{
	bWasTargetShoved = true;
	UE_LOG(LogTemp, Log, TEXT("AAshenProtectiveInterceptDecoyActor: Decoy successfully shoved out of impact zone."));
}
