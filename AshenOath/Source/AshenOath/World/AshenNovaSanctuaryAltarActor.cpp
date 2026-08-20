// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenNovaSanctuaryAltarActor.h"

AAshenNovaSanctuaryAltarActor::AAshenNovaSanctuaryAltarActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsAltarConsecrated = false;
}
void AAshenNovaSanctuaryAltarActor::BeginPlay() { Super::BeginPlay(); }

bool AAshenNovaSanctuaryAltarActor::ConsecrateNovaAltar(AActor* InstigatingPlayer)
{
	if (!InstigatingPlayer) return false;
	bIsAltarConsecrated = true;
	UE_LOG(LogTemp, Warning, TEXT("AAshenNovaSanctuaryAltarActor: Nova Sanctuary Altar consecrated! Integration Debt purified."));
	return true;
}
