// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenOathSwornVisualFlourishActor.h"

AAshenOathSwornVisualFlourishActor::AAshenOathSwornVisualFlourishActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenOathSwornVisualFlourishActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenOathSwornVisualFlourishActor: Oath sworn visual flourish actor initialized."));
}

void AAshenOathSwornVisualFlourishActor::TriggerOathSwornVisualFlourish()
{
	UE_LOG(LogTemp, Warning, TEXT("AAshenOathSwornVisualFlourishActor: Golden oath rune particle burst triggered!"));
}
