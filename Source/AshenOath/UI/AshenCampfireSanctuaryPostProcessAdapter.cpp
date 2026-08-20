// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenCampfireSanctuaryPostProcessAdapter.h"

UAshenCampfireSanctuaryPostProcessAdapter::UAshenCampfireSanctuaryPostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenCampfireSanctuaryPostProcessAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenCampfireSanctuaryPostProcessAdapter::ApplyCampfireSanctuaryPostProcess(bool bInSanctuary, float WarmthIntensity)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenCampfireSanctuaryPostProcessAdapter: Postprocess updated — Sanctuary: %s | Warmth: %.2f (Amber glow & bloom active)"),
		bInSanctuary ? TEXT("ACTIVE") : TEXT("INACTIVE"), WarmthIntensity);
}
