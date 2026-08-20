// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Audio/AshenRehabilitationAudioResonatorComponent.h"

UAshenRehabilitationAudioResonatorComponent::UAshenRehabilitationAudioResonatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenRehabilitationAudioResonatorComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenRehabilitationAudioResonatorComponent::TriggerHarmonicResonanceChord()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenRehabilitationAudioResonatorComponent: Therapeutic harmonic chord triggered cleanly!"));
}
