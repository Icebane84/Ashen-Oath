// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenIllusoryDoorwayActor.h"

AAshenIllusoryDoorwayActor::AAshenIllusoryDoorwayActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenIllusoryDoorwayActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenIllusoryDoorwayActor: Illusory doorway actor active."));
}

void AAshenIllusoryDoorwayActor::SetIllusoryState(bool bActive)
{
	bIsDoorwayIllusionActive = bActive;
	UE_LOG(LogTemp, Warning, TEXT("AAshenIllusoryDoorwayActor: Illusory doorway set to %s (Appears %s)"),
		bIsDoorwayIllusionActive ? TEXT("ACTIVE") : TEXT("INACTIVE"),
		bIsDoorwayIllusionActive ? TEXT("SOLID WALL") : TEXT("OPEN DOORWAY"));
}
