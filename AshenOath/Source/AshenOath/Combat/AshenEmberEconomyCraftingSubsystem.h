// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenEmberEconomyCraftingSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnItemCraftedSignature, FName, ItemID, float, EmbersSpent);

/**
 * UAshenEmberEconomyCraftingSubsystem
 *
 * World Subsystem managing Ember & Ash currency exchange, weapon forging, and item crafting.
 */
UCLASS()
class ASHENOATH_API UAshenEmberEconomyCraftingSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Crafting")
	bool CraftItemWithEmbers(FName ItemID, float EmberCost, AActor* CraftingActor);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Crafting|Events")
	FOnItemCraftedSignature OnItemCrafted;
};
