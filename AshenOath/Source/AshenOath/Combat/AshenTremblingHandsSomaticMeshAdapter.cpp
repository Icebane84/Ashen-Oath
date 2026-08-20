// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenTremblingHandsSomaticMeshAdapter.h"

UAshenTremblingHandsSomaticMeshAdapter::UAshenTremblingHandsSomaticMeshAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	TrembleAmplitudeScalar = 0.0f;
}
void UAshenTremblingHandsSomaticMeshAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenTremblingHandsSomaticMeshAdapter::UpdateTrembleAmplitude(float InTremble)
{
	TrembleAmplitudeScalar = FMath::Clamp(InTremble, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenTremblingHandsSomaticMeshAdapter: Procedural Hand Tremble Amplitude: %.2f"),
		TrembleAmplitudeScalar);
}
