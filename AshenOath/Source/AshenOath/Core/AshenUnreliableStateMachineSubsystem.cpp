// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 302: Ashen Unreliable State Machine Subsystem (UMB-SYS-005)

#include "AshenUnreliableStateMachineSubsystem.h"

void UAshenUnreliableStateMachineSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	CurrentInterfaceMode = EAshenInterfaceMode::DiegeticOnly;
	UE_LOG(LogTemp, Log, TEXT("UAshenUnreliableStateMachineSubsystem: Initialized — Unreliable State Machine (UMB-SYS-005) ONLINE."));
}

void UAshenUnreliableStateMachineSubsystem::SetInterfaceMode(EAshenInterfaceMode NewMode)
{
	CurrentInterfaceMode = NewMode;
	OnInterfaceModeChanged.Broadcast(NewMode);

	UE_LOG(LogTemp, Warning, TEXT("UAshenUnreliableStateMachineSubsystem: INTERFACE MODE SHIFTED -> Mode %d (UMB-SYS-005)."), (int32)NewMode);
}
