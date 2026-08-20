// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenSilentSpireMemoryEchoActor.h"

AAshenSilentSpireMemoryEchoActor::AAshenSilentSpireMemoryEchoActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsEchoReconstructed = false;
}
void AAshenSilentSpireMemoryEchoActor::BeginPlay() { Super::BeginPlay(); }

void AAshenSilentSpireMemoryEchoActor::TriggerSpireMemoryEcho()
{
	bIsEchoReconstructed = true;
	UE_LOG(LogTemp, Warning, TEXT("AAshenSilentSpireMemoryEchoActor: THE SILENT SPIRE MEMORY ECHO RECONSTRUCTED!"));
}
