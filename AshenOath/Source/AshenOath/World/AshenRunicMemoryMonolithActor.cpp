// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenRunicMemoryMonolithActor.h"

AAshenRunicMemoryMonolithActor::AAshenRunicMemoryMonolithActor()
{
	PrimaryActorTick.bCanEverTick = false;
	UnlockedCodexID = NAME_None;
	bIsDeciphered = false;
}
void AAshenRunicMemoryMonolithActor::BeginPlay() { Super::BeginPlay(); }

bool AAshenRunicMemoryMonolithActor::DecipherMonolith(AActor* InstigatingPlayer)
{
	if (!InstigatingPlayer) return false;
	bIsDeciphered = true;
	UE_LOG(LogTemp, Warning, TEXT("AAshenRunicMemoryMonolithActor: Deciphered Monolith Runes for Codex ID '%s'!"),
		*UnlockedCodexID.ToString());
	return true;
}
