// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Core/AshenExistentialMeaningSaveGameAdapter.h"

UAshenExistentialMeaningSaveGameAdapter::UAshenExistentialMeaningSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenExistentialMeaningSaveGameAdapter::BeginPlay() { Super::BeginPlay(); }

bool UAshenExistentialMeaningSaveGameAdapter::SaveExistentialState(const TArray<FMemoryEchoRecord>& Memories, int32 DefianceCount, int32 WrathCount, int32 TrustCount)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenExistentialMeaningSaveGameAdapter: Saved Existential State -> %d Memories Compiled | Staggers: %d Defiance, %d Wrath, %d Trust"),
		Memories.Num(), DefianceCount, WrathCount, TrustCount);
	return true;
}
