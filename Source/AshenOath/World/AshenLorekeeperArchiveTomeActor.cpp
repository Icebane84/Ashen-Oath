// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenLorekeeperArchiveTomeActor.h"

AAshenLorekeeperArchiveTomeActor::AAshenLorekeeperArchiveTomeActor()
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryFactionFocus = ECodexFaction::Oathsworn;
	bIsTomeOpen = false;
}
void AAshenLorekeeperArchiveTomeActor::BeginPlay() { Super::BeginPlay(); }

bool AAshenLorekeeperArchiveTomeActor::OpenTome(AActor* InstigatingPlayer)
{
	if (!InstigatingPlayer) return false;
	bIsTomeOpen = true;
	UE_LOG(LogTemp, Warning, TEXT("AAshenLorekeeperArchiveTomeActor: Opened Lorekeeper Archive Tome (Faction: %d)."),
		static_cast<int32>(PrimaryFactionFocus));
	return true;
}
