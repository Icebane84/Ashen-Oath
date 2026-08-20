// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenDualityTransformationLocusActor.h"

AAshenDualityTransformationLocusActor::AAshenDualityTransformationLocusActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenDualityTransformationLocusActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenDualityTransformationLocusActor: Duality Transformation Locus Actor initialized."));
}

bool AAshenDualityTransformationLocusActor::TriggerDualityTransformationAuraPulse()
{
	UE_LOG(LogTemp, Log, TEXT("AAshenDualityTransformationLocusActor: Triggered duality transformation aura pulse (Radius: %f)."), TransformationLocusRadius);
	return true;
}
