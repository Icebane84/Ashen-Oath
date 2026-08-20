// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenAnvilWeaponUpgradeLocusActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAnvilForgeExecutedSignature, FName, UpgradeRuneTag, bool, bDurabilityRestored);

/**
 * AAshenAnvilWeaponUpgradeLocusActor
 *
 * Interactive sanctuary anvil locus for forging runic upgrades and restoring blade durability (PRS-001 Oathbringer Slice).
 */
UCLASS()
class ASHENOATH_API AAshenAnvilWeaponUpgradeLocusActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenAnvilWeaponUpgradeLocusActor();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|AnvilLocus")
	void ForgeWeaponUpgrade(FName RuneTag);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|AnvilLocus|Events")
	FOnAnvilForgeExecutedSignature OnAnvilForgeExecuted;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|AnvilLocus")
	bool bIsAnvilActive = true;
};
