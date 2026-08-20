// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenHeartstoneSubsystem.h"

void UAshenHeartstoneSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	TotalForgedTraits = 0;
	UE_LOG(LogTemp, Log, TEXT("UAshenHeartstoneSubsystem: Heartstone Subsystem initialized."));
}

bool UAshenHeartstoneSubsystem::TransmuteRemnantsToPerk(FName TraitID, int32 RequiredRemnants, float DebtReduction)
{
	TotalForgedTraits++;
	if (OnHeartstoneCrucibleForged.IsBound())
	{
		OnHeartstoneCrucibleForged.Broadcast(TraitID, DebtReduction);
	}
	UE_LOG(LogTemp, Warning, TEXT("UAshenHeartstoneSubsystem: Trait '%s' forged from %d remnants! Integration debt reduced by %.1f (Total: %d)."),
		*TraitID.ToString(), RequiredRemnants, DebtReduction, TotalForgedTraits);
	return true;
}
