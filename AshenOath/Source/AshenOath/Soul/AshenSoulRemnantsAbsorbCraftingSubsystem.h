// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenSoulRemnantsAbsorbCraftingSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnBlueprintUnlockedSignature, FName, BlueprintID, int32, TotalBlueprints);

/**
 * UAshenSoulRemnantsAbsorbCraftingSubsystem
 *
 * World Subsystem managing the absorption of Soul Remnants to unlock ancient weapon blueprints and lore schematics.
 */
UCLASS()
class ASHENOATH_API UAshenSoulRemnantsAbsorbCraftingSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|AbsorbCrafting")
	bool UnlockBlueprintFromAbsorbedRemnant(FName BlueprintID);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|AbsorbCrafting|Events")
	FOnBlueprintUnlockedSignature OnBlueprintUnlocked;

private:
	TSet<FName> UnlockedBlueprints;
};
