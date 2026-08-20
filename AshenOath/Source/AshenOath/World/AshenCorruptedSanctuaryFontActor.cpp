// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenCorruptedSanctuaryFontActor.h"

AAshenCorruptedSanctuaryFontActor::AAshenCorruptedSanctuaryFontActor()
{
	PrimaryActorTick.bCanEverTick = false;
	ActivationRadius = 600.0f;
	bIsFontHarmonized = false;
}
void AAshenCorruptedSanctuaryFontActor::BeginPlay() { Super::BeginPlay(); }

bool AAshenCorruptedSanctuaryFontActor::HarmonizeFont(AActor* InstigatingPlayer, float CurrentCorruption)
{
	if (!InstigatingPlayer || CurrentCorruption < 0.50f) return false;
	bIsFontHarmonized = true;
	UE_LOG(LogTemp, Warning, TEXT("AAshenCorruptedSanctuaryFontActor: Font harmonized by Shadow Mark Seepage (Corruption: %.2f)!"),
		CurrentCorruption);
	return true;
}
