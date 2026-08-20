// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenMemoryPalacePostProcessAdapter.h"

UAshenMemoryPalacePostProcessAdapter::UAshenMemoryPalacePostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenMemoryPalacePostProcessAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenMemoryPalacePostProcessAdapter::ApplyMindscapeDreamGrading(bool bInMindscape, float TraumaDensity)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenMemoryPalacePostProcessAdapter: Mindscape Dream Post-Process %s (Trauma Density: %.2f)."),
		bInMindscape ? TEXT("ACTIVE") : TEXT("INACTIVE"), TraumaDensity);
}
