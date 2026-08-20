// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 180: Ashen Fast Travel Subsystem

#include "AshenFastTravelSubsystem.h"
#include "GameFramework/Pawn.h"
#include "Engine/World.h"

void UAshenFastTravelSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	Sanctuaries.Empty();
	UE_LOG(LogTemp, Log, TEXT("UAshenFastTravelSubsystem: Initialized — Fast Travel Network ready."));
}

void UAshenFastTravelSubsystem::RegisterSanctuary(FName SanctuaryID, FVector Location, bool bAutoUnlock)
{
	if (SanctuaryID.IsNone()) return;

	FSanctuaryData Data;
	Data.Location = Location;
	Data.bIsUnlocked = bAutoUnlock;

	Sanctuaries.Add(SanctuaryID, Data);

	UE_LOG(LogTemp, Log, TEXT("UAshenFastTravelSubsystem: Registered sanctuary '%s' at (%.0f, %.0f, %.0f) [Unlocked: %s]."),
		*SanctuaryID.ToString(), Location.X, Location.Y, Location.Z, bAutoUnlock ? TEXT("YES") : TEXT("NO"));

	if (bAutoUnlock)
	{
		OnSanctuaryDiscovered.Broadcast(SanctuaryID, Location);
	}
}

bool UAshenFastTravelSubsystem::UnlockSanctuary(FName SanctuaryID)
{
	FSanctuaryData* Data = Sanctuaries.Find(SanctuaryID);
	if (!Data)
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenFastTravelSubsystem: Cannot unlock unknown sanctuary '%s'."), *SanctuaryID.ToString());
		return false;
	}

	if (Data->bIsUnlocked) return true; // Already unlocked

	Data->bIsUnlocked = true;
	OnSanctuaryDiscovered.Broadcast(SanctuaryID, Data->Location);

	UE_LOG(LogTemp, Warning, TEXT("UAshenFastTravelSubsystem: DISCOVERED & UNLOCKED Sanctuary '%s'!"), *SanctuaryID.ToString());
	return true;
}

bool UAshenFastTravelSubsystem::FastTravelToSanctuary(APawn* PlayerPawn, FName TargetSanctuaryID)
{
	if (!PlayerPawn)
	{
		UE_LOG(LogTemp, Error, TEXT("UAshenFastTravelSubsystem: FastTravel failed — Null PlayerPawn."));
		return false;
	}

	FSanctuaryData* Target = Sanctuaries.Find(TargetSanctuaryID);
	if (!Target || !Target->bIsUnlocked)
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenFastTravelSubsystem: FastTravel failed — Sanctuary '%s' is invalid or locked."), *TargetSanctuaryID.ToString());
		return false;
	}

	// Perform teleport
	PlayerPawn->SetActorLocation(Target->Location);
	OnFastTravelCompleted.Broadcast(TargetSanctuaryID, Target->Location);

	UE_LOG(LogTemp, Warning, TEXT("UAshenFastTravelSubsystem: FAST TRAVEL SUCCESS — Teleported '%s' to '%s' (%.0f, %.0f, %.0f)."),
		*PlayerPawn->GetName(), *TargetSanctuaryID.ToString(), Target->Location.X, Target->Location.Y, Target->Location.Z);

	return true;
}

bool UAshenFastTravelSubsystem::IsSanctuaryUnlocked(FName SanctuaryID) const
{
	const FSanctuaryData* Data = Sanctuaries.Find(SanctuaryID);
	return Data ? Data->bIsUnlocked : false;
}

TArray<FName> UAshenFastTravelSubsystem::GetUnlockedSanctuaries() const
{
	TArray<FName> UnlockedList;
	for (const auto& KVP : Sanctuaries)
	{
		if (KVP.Value.bIsUnlocked)
		{
			UnlockedList.Add(KVP.Key);
		}
	}
	return UnlockedList;
}
