// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Memory/AshenMindscapeFractureEchoVolume.h"

AAshenMindscapeFractureEchoVolume::AAshenMindscapeFractureEchoVolume()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenMindscapeFractureEchoVolume::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenMindscapeFractureEchoVolume: Mindscape fracture volume initialized with instability index %f."), FractureInstabilityIndex);
}

void AAshenMindscapeFractureEchoVolume::TriggerFractureImprintReflection(AActor* InstigatorActor)
{
	if (!InstigatorActor) return;
	UE_LOG(LogTemp, Log, TEXT("AAshenMindscapeFractureEchoVolume: Triggered psychic fracture imprint reflection for instigator %s"), *InstigatorActor->GetName());
}
