// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenLorekeeperSanctuaryPedestalActor.h"

AAshenLorekeeperSanctuaryPedestalActor::AAshenLorekeeperSanctuaryPedestalActor()
{
	PrimaryActorTick.bCanEverTick = false;
	SecuredRelicID = NAME_None;
	bIsRelicRestored = false;
}
void AAshenLorekeeperSanctuaryPedestalActor::BeginPlay() { Super::BeginPlay(); }

bool AAshenLorekeeperSanctuaryPedestalActor::RestoreRelic(AActor* InstigatingPlayer)
{
	if (!InstigatingPlayer) return false;
	bIsRelicRestored = true;
	UE_LOG(LogTemp, Warning, TEXT("AAshenLorekeeperSanctuaryPedestalActor: Relic '%s' restored to Sanctuary Pedestal!"),
		*SecuredRelicID.ToString());
	return true;
}
