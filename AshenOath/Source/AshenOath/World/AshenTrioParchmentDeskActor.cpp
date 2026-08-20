// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenTrioParchmentDeskActor.h"

AAshenTrioParchmentDeskActor::AAshenTrioParchmentDeskActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsDeskOpen = false;
}
void AAshenTrioParchmentDeskActor::BeginPlay() { Super::BeginPlay(); }

void AAshenTrioParchmentDeskActor::OpenParchmentDesk(AActor* InstigatingPlayer)
{
	if (!InstigatingPlayer) return;
	bIsDeskOpen = true;
	UE_LOG(LogTemp, Log, TEXT("AAshenTrioParchmentDeskActor: Trio Parchment Desk opened by %s."), *InstigatingPlayer->GetName());
}
