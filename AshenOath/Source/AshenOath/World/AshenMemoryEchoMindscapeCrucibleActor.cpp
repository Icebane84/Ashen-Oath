// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenMemoryEchoMindscapeCrucibleActor.h"

AAshenMemoryEchoMindscapeCrucibleActor::AAshenMemoryEchoMindscapeCrucibleActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsMindscapeCrucibleActive = false;
}
void AAshenMemoryEchoMindscapeCrucibleActor::BeginPlay() { Super::BeginPlay(); }

void AAshenMemoryEchoMindscapeCrucibleActor::OpenMemoryEchoMindscape(FName MemoryID)
{
	bIsMindscapeCrucibleActive = true;
	UE_LOG(LogTemp, Warning, TEXT("AAshenMemoryEchoMindscapeCrucibleActor: OPENED MINDSCAPE CRUCIBLE for Memory [%s]! Ready for Keystone Compilation!"),
		*MemoryID.ToString());
}
