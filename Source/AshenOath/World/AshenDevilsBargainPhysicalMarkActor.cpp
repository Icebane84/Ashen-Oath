// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenDevilsBargainPhysicalMarkActor.h"

AAshenDevilsBargainPhysicalMarkActor::AAshenDevilsBargainPhysicalMarkActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenDevilsBargainPhysicalMarkActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenDevilsBargainPhysicalMarkActor: Devil's Bargain Physical Mark Actor initialized."));
}

bool AAshenDevilsBargainPhysicalMarkActor::TriggerInWorldMarkRunePulse()
{
	UE_LOG(LogTemp, Log, TEXT("AAshenDevilsBargainPhysicalMarkActor: Triggered in-world forearm Mark rune pulse (Intensity: %f)."), MarkRunePulseIntensity);
	return true;
}
