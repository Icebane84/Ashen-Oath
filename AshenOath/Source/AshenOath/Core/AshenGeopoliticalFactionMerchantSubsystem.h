// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenGeopoliticalFactionMerchantSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnFactionInventoryUnlockedSignature, FName, FactionID, int32, UnlockedItemTier);

/**
 * UAshenGeopoliticalFactionMerchantSubsystem
 *
 * World Subsystem unlocking exclusive faction merchant inventory based on Geopolitical Standing.
 */
UCLASS()
class ASHENOATH_API UAshenGeopoliticalFactionMerchantSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|FactionMerchant")
	void RefreshFactionMerchantTier(FName FactionID, float CurrentStanding);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|FactionMerchant|Events")
	FOnFactionInventoryUnlockedSignature OnInventoryUnlocked;

private:
	TMap<FName, int32> FactionUnlockedTiers;
};
