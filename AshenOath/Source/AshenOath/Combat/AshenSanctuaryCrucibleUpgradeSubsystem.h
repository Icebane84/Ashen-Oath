// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenSanctuaryCrucibleUpgradeSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCrucibleUpgradeTierReachedSignature, int32, UpgradeTier, float, GlobalMultiplier);

/**
 * UAshenSanctuaryCrucibleUpgradeSubsystem
 *
 * World Subsystem handling Heartstone Crucible upgrade tiers and global party passive unlocks.
 */
UCLASS()
class ASHENOATH_API UAshenSanctuaryCrucibleUpgradeSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|CrucibleUpgrade")
	bool UpgradeCrucibleTier();

	UFUNCTION(BlueprintPure, Category = "AshenOath|CrucibleUpgrade")
	int32 GetCurrentCrucibleTier() const { return CurrentCrucibleTier; }

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|CrucibleUpgrade|Events")
	FOnCrucibleUpgradeTierReachedSignature OnCrucibleTierReached;

private:
	int32 CurrentCrucibleTier = 1;
};
