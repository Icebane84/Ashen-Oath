// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenHallucinationPostProcessAdapter.h"

UAshenHallucinationPostProcessAdapter::UAshenHallucinationPostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenHallucinationPostProcessAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenHallucinationPostProcessAdapter::ApplyHallucinatoryPostProcess(uint8 StateEnum, float Severity)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenHallucinationPostProcessAdapter: Hallucinatory PostProcess State: %d | Severity: %.2f (Spatial static & double-vision active)"),
		StateEnum, Severity);
}
