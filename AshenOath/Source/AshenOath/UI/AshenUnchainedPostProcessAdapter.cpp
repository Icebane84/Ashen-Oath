// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUnchainedPostProcessAdapter.h"

UAshenUnchainedPostProcessAdapter::UAshenUnchainedPostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenUnchainedPostProcessAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenUnchainedPostProcessAdapter::ApplyUnchainedPostProcess(bool bIsBerserkActive, float BerserkIntensity)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenUnchainedPostProcessAdapter: PostProcess updated — Berserk: %s | Intensity: %.2f (Blood-red vignette & chromatic aberration active)"),
		bIsBerserkActive ? TEXT("ACTIVE") : TEXT("INACTIVE"), BerserkIntensity);
}
