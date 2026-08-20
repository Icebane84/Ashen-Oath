// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 551: Ashen Lorekeeper Memory Weaver Component

#include "AshenLorekeeperMemoryWeaverComponent.h"

UAshenLorekeeperMemoryWeaverComponent::UAshenLorekeeperMemoryWeaverComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	TotalMemoriesWeaved = 0;
}

bool UAshenLorekeeperMemoryWeaverComponent::WeaveMemoryImprint(FName MemoryID, float EncryptedDepth)
{
	if (MemoryID.IsNone()) return false;

	TotalMemoriesWeaved++;
	const float Clarity = FMath::Clamp(1.0f - (EncryptedDepth / 100.0f), 0.1f, 1.0f);

	OnMemoryWeaveCompleted.Broadcast(MemoryID, Clarity);

	UE_LOG(LogTemp, Warning, TEXT("UAshenLorekeeperMemoryWeaverComponent: MEMORY WEAVE COMPLETED -> '%s' (Clarity: %.2f | Total: %d)."),
		*MemoryID.ToString(), Clarity, TotalMemoriesWeaved);

	return true;
}
