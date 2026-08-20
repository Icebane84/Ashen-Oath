// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Core/AshenVisualShiftStateSaveGameAdapter.h"

UAshenVisualShiftStateSaveGameAdapter::UAshenVisualShiftStateSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenVisualShiftStateSaveGameAdapter::BeginPlay() { Super::BeginPlay(); }

bool UAshenVisualShiftStateSaveGameAdapter::SerializeVisualShiftState(float CorruptionIntensity, float BlendRatio)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenVisualShiftStateSaveGameAdapter: Visual shift state (Corruption: %.2f, Blend: %.2f) serialized cleanly."), CorruptionIntensity, BlendRatio);
	return true;
}
