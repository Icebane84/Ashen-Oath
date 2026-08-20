// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Crafting/AshenAlchemicalCraftingTypes.h"
#include "AshenAlchemicalCraftingSubsystem.generated.h"

/**
 * UAshenAlchemicalCraftingSubsystem
 * GameInstance Subsystem managing the alchemical recipe registry, reagent stockpiles, and campfire workstation synthesis states.
 */
UCLASS()
class ASHENOATH_API UAshenAlchemicalCraftingSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Crafting")
	int32 StockpileGloomwoodSap = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Crafting")
	int32 StockpileGhostbloom = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Crafting")
	int32 StockpileSulfurDust = 0;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Crafting")
	void AddReagent(EAlchemicalReagent Reagent, int32 Amount);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Crafting")
	bool CanCraftRecipe(const FAlchemicalRecipe& Recipe) const;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Crafting")
	bool ExecuteCraftRecipe(const FAlchemicalRecipe& Recipe);
};
