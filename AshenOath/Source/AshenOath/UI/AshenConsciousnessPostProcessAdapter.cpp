// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenConsciousnessPostProcessAdapter.h"

UAshenConsciousnessPostProcessAdapter::UAshenConsciousnessPostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenConsciousnessPostProcessAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenConsciousnessPostProcessAdapter::TriggerTacticalAudioEdgePulse(float Intensity)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenConsciousnessPostProcessAdapter: Audio-Reactive Edge Pulse (Intensity: %.2f)"), Intensity);
}
