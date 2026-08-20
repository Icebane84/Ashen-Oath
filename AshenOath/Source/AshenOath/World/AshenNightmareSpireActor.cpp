// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenNightmareSpireActor.h"

AAshenNightmareSpireActor::AAshenNightmareSpireActor()
{
	PrimaryActorTick.bCanEverTick = false;
	CorruptionAuraRadius = 1600.0f;
	bIsSpirePurified = false;
}
void AAshenNightmareSpireActor::BeginPlay() { Super::BeginPlay(); }

bool AAshenNightmareSpireActor::PurifySpire(AActor* InstigatingPlayer)
{
	if (!InstigatingPlayer) return false;
	bIsSpirePurified = true;
	UE_LOG(LogTemp, Warning, TEXT("AAshenNightmareSpireActor: Nightmare Spire successfully purified!"));
	return true;
}
