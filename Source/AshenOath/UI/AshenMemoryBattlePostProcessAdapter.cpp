// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenMemoryBattlePostProcessAdapter.h"

UAshenMemoryBattlePostProcessAdapter::UAshenMemoryBattlePostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenMemoryBattlePostProcessAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenMemoryBattlePostProcessAdapter::ApplyMemoryBattlePostProcess(float Intensity, bool bVictoryFlash)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenMemoryBattlePostProcessAdapter: Memory Battle PostProcess applied (Intensity: %.2f, VictoryFlash: %s)"),
		Intensity, bVictoryFlash ? TEXT("TRUE") : TEXT("FALSE"));
}
