// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenBossArenaEnvironmentalPostProcessAdapter.h"

UAshenBossArenaEnvironmentalPostProcessAdapter::UAshenBossArenaEnvironmentalPostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenBossArenaEnvironmentalPostProcessAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenBossArenaEnvironmentalPostProcessAdapter::ApplyBossArenaPhasePostProcess(uint8 PhaseIndex)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenBossArenaEnvironmentalPostProcessAdapter: Boss Arena PostProcess updated for Phase %d."), PhaseIndex);
}
