// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Audio/AshenDiegeticVoiceModulationComponent.h"

UAshenDiegeticVoiceModulationComponent::UAshenDiegeticVoiceModulationComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenDiegeticVoiceModulationComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenDiegeticVoiceModulationComponent::ApplyVoiceDSPFilter(bool bInMindscape, float DebtLevel)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticVoiceModulationComponent: DSP Filter updated — Mindscape Muffle: %s | Panicked Pitch Shift: %.2f"),
		bInMindscape ? TEXT("YES") : TEXT("NO"), DebtLevel);
}
