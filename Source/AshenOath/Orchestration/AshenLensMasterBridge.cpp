// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Orchestration/AshenLensMasterBridge.h"

UAshenLensMasterBridge::UAshenLensMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenLensMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	bLensBridgeActive = true;
}

void UAshenLensMasterBridge::BroadcastLensSelectionPulse(EInterpretiveLens NewLens, const FSoulStateVector& CompiledVector)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenLensMasterBridge: Broadcasted Lens Selection Pulse (Lens: %d, Compiled Resolve: %.2f)."),
		static_cast<int32>(NewLens), CompiledVector.Resolve);
}
