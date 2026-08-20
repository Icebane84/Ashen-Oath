// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenCompanionFatiguePostProcessAdapter.h"

UAshenCompanionFatiguePostProcessAdapter::UAshenCompanionFatiguePostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenCompanionFatiguePostProcessAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenCompanionFatiguePostProcessAdapter::ApplyResonanceGlow(bool bActive)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenCompanionFatiguePostProcessAdapter: Resonance Golden Lens Bloom %s."),
		bActive ? TEXT("ENABLED") : TEXT("DISABLED"));
}
