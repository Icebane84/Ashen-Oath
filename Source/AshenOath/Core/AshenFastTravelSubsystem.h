// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenFastTravelSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSanctuaryDiscoveredSignature, FName, SanctuaryID, FVector, Location);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnFastTravelCompletedSignature, FName, TargetSanctuaryID, FVector, Destination);

/**
 * UAshenFastTravelSubsystem
 *
 * World Subsystem managing fast travel between unlocked sanctuaries/campfires.
 * Tracks unlocked sanctuary IDs and coordinates player teleportation with optional sanity cost or level checks.
 */
UCLASS()
class ASHENOATH_API UAshenFastTravelSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	// --- Public API ---
	UFUNCTION(BlueprintCallable, Category = "AshenOath|FastTravel")
	void RegisterSanctuary(FName SanctuaryID, FVector Location, bool bAutoUnlock = false);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|FastTravel")
	bool UnlockSanctuary(FName SanctuaryID);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|FastTravel")
	bool FastTravelToSanctuary(APawn* PlayerPawn, FName TargetSanctuaryID);

	UFUNCTION(BlueprintPure, Category = "AshenOath|FastTravel")
	bool IsSanctuaryUnlocked(FName SanctuaryID) const;

	UFUNCTION(BlueprintPure, Category = "AshenOath|FastTravel")
	TArray<FName> GetUnlockedSanctuaries() const;

	// --- Delegates ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|FastTravel|Events")
	FOnSanctuaryDiscoveredSignature OnSanctuaryDiscovered;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|FastTravel|Events")
	FOnFastTravelCompletedSignature OnFastTravelCompleted;

private:
	struct FSanctuaryData
	{
		FVector Location = FVector::ZeroVector;
		bool bIsUnlocked = false;
	};

	TMap<FName, FSanctuaryData> Sanctuaries;
};
