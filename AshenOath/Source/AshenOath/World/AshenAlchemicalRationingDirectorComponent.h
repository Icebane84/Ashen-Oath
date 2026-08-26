// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenCampfireCookingTypes.h"
#include "AshenAlchemicalRationingDirectorComponent.generated.h"

/**
 * UAshenAlchemicalRationingDirectorComponent
 * 
 * Coordinates campfire culinary preparation, stirring timing windows, and companion portion distribution.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenAlchemicalRationingDirectorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenAlchemicalRationingDirectorComponent();

	/** Validates if all required ingredients are present for recipe */
	UFUNCTION(BlueprintPure, Category = "Ashen|Cooking|Director")
	bool ValidateIngredientsForRecipe(ECampfireRecipeType Recipe, int32 MeatCount, int32 HerbCount, int32 SaltCount) const;

	/** Gets the optimal boiling temperature in Celsius */
	UFUNCTION(BlueprintPure, Category = "Ashen|Cooking|Director")
	float GetOptimalBoilingTemperatureCelsius() const { return 95.0f; }
};
