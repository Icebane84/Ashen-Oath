// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Orchestration/AshenModularSliceStateBridgeSubsystem.h"

void UAshenModularSliceStateBridgeSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenModularSliceStateBridgeSubsystem: Master Slice State Bridge Subsystem Initialized."));
}

void UAshenModularSliceStateBridgeSubsystem::DispatchStatePulse(const FSoulStateVector& NewState)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenModularSliceStateBridgeSubsystem: Dispathing state pulse to all 5 modular slices (Resolve: %.2f, Corruption: %.2f)"),
		NewState.Resolve, NewState.Corruption);
}
