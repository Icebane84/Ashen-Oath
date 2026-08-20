// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Audio/AshenDiegeticLensAudioComponent.h"

UAshenDiegeticLensAudioComponent::UAshenDiegeticLensAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenDiegeticLensAudioComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenDiegeticLensAudioComponent::PlayLensSelectionCue(EInterpretiveLens Lens)
{
	FString LensSound = TEXT("Grace Harmonic Chimes");
	if (Lens == EInterpretiveLens::Accountability) LensSound = TEXT("Accountability Anvil Strike");
	else if (Lens == EInterpretiveLens::Utility) LensSound = TEXT("Utility Clockwork Crystal");

	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticLensAudioComponent: Played %s audio cue."), *LensSound);
}
