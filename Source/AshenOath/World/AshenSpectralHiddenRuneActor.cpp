// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenSpectralHiddenRuneActor.h"

AAshenSpectralHiddenRuneActor::AAshenSpectralHiddenRuneActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenSpectralHiddenRuneActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenSpectralHiddenRuneActor: Spectral hidden rune actor initialized."));
}

void AAshenSpectralHiddenRuneActor::RevealSpectralRune()
{
	bIsRuneRevealed = true;
	UE_LOG(LogTemp, Warning, TEXT("AAshenSpectralHiddenRuneActor: Hidden spectral rune REVEALED by alchemical light beam!"));
}
