// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 637: Ashen CAN Anchor Registry Subsystem

#include "AshenCANAnchorRegistrySubsystem.h"

void UAshenCANAnchorRegistrySubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	RegisteredCANIDs.Empty();
	UE_LOG(LogTemp, Log, TEXT("UAshenCANAnchorRegistrySubsystem: Initialized — CAN Anchor Registry Subsystem ONLINE."));
}

void UAshenCANAnchorRegistrySubsystem::RegisterCANAnchor(FName CANAnchorID, FString ConflictSummary)
{
	if (CANAnchorID.IsNone()) return;

	RegisteredCANIDs.AddUnique(CANAnchorID);
	OnCANRegistered.Broadcast(CANAnchorID, ConflictSummary);

	UE_LOG(LogTemp, Warning, TEXT("UAshenCANAnchorRegistrySubsystem: CAN ANCHOR REGISTERED -> '%s' | Summary: '%s' (Total: %d)."),
		*CANAnchorID.ToString(), *ConflictSummary, RegisteredCANIDs.Num());
}
