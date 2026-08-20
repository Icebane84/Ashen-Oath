// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenEpistemicPostProcessAdapter.h"

UAshenEpistemicPostProcessAdapter::UAshenEpistemicPostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenEpistemicPostProcessAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenEpistemicPostProcessAdapter::TriggerMilestoneConvergencePostProcess(bool bIsSynarchy)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenEpistemicPostProcessAdapter: Triggered Milestone Convergence Post-Process (Synarchy: %s)."),
		bIsSynarchy ? TEXT("GOLDEN FLARE") : TEXT("OBSIDIAN DISTORTION"));
}
