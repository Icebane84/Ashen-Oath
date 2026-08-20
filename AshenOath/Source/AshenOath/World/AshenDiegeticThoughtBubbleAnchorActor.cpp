// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenDiegeticThoughtBubbleAnchorActor.h"

AAshenDiegeticThoughtBubbleAnchorActor::AAshenDiegeticThoughtBubbleAnchorActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenDiegeticThoughtBubbleAnchorActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenDiegeticThoughtBubbleAnchorActor: Thought bubble anchor initialized."));
}

void AAshenDiegeticThoughtBubbleAnchorActor::SpawnInWorldThoughtBubble(FText ThoughtText, FVector WorldLocation)
{
	UE_LOG(LogTemp, Log, TEXT("AAshenDiegeticThoughtBubbleAnchorActor: In-world thought bubble spawned: '%s' at (%f, %f, %f)"),
		*ThoughtText.ToString(), WorldLocation.X, WorldLocation.Y, WorldLocation.Z);
}
