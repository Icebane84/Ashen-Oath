// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenSerafinaStainedCuffMeshAdapter.h"

UAshenSerafinaStainedCuffMeshAdapter::UAshenSerafinaStainedCuffMeshAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	BlackSapStainCoverage = 0.0f;
}
void UAshenSerafinaStainedCuffMeshAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenSerafinaStainedCuffMeshAdapter::UpdateCuffStain(float TransferenceScalar)
{
	BlackSapStainCoverage = FMath::Clamp(TransferenceScalar, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenSerafinaStainedCuffMeshAdapter: Serafina White Wool Cuff Black Sap Stain Coverage: %.2f"),
		BlackSapStainCoverage);
}
