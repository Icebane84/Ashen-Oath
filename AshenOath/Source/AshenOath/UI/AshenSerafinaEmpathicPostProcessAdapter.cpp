// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenSerafinaEmpathicPostProcessAdapter.h"

UAshenSerafinaEmpathicPostProcessAdapter::UAshenSerafinaEmpathicPostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenSerafinaEmpathicPostProcessAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenSerafinaEmpathicPostProcessAdapter::ApplyEmpathicTransferenceBloom(bool bIsTransferenceActive, float BurnoutLevel)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenSerafinaEmpathicPostProcessAdapter: PostProcess updated — Transference: %s | Burnout Haze: %.1f"),
		bIsTransferenceActive ? TEXT("ACTIVE") : TEXT("INACTIVE"), BurnoutLevel);
}
