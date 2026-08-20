// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 343: Ashen Resonant Armaments Subsystem

#include "AshenResonantArmamentsSubsystem.h"

void UAshenResonantArmamentsSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	ImprintedArmaments.Empty();
	UE_LOG(LogTemp, Log, TEXT("UAshenResonantArmamentsSubsystem: Initialized — Resonant Armaments System active."));
}

bool UAshenResonantArmamentsSubsystem::ImprintMemoryOnArmament(FName ArmamentID, FName MemoryID)
{
	if (ArmamentID.IsNone() || MemoryID.IsNone()) return false;

	ImprintedArmaments.Add(ArmamentID, MemoryID);
	OnArmamentEnchanted.Broadcast(ArmamentID, MemoryID);

	UE_LOG(LogTemp, Warning, TEXT("UAshenResonantArmamentsSubsystem: MEMORY IMPRINTED — Armament '%s' infused with Memory '%s'."),
		*ArmamentID.ToString(), *MemoryID.ToString());

	return true;
}
