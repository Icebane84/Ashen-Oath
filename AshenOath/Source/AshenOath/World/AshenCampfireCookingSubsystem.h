// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "World/AshenCampfireCookingTypes.h"
#include "AshenCampfireCookingSubsystem.generated.h"

/**
 * UAshenCampfireCookingSubsystem
 * 
 * Central world subsystem governing campfire cauldron cooking, meal distribution, and alchemical field nutrition.
 */
UCLASS()
class ASHENOATH_API UAshenCampfireCookingSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenCampfireCookingSubsystem();

	/** Starts preparing a new recipe */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Cooking")
	bool BeginCookingRecipe(ECampfireRecipeType Recipe);

	/** Adds stirring rhythm input (advances cooking progress) */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Cooking")
	void ApplyStirringInput(float RhythmAccuracy01);

	/** Serves and consumes one portion of the cooked meal */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Cooking")
	bool ConsumeMealPortion();

	UFUNCTION(BlueprintPure, Category = "Ashen|Cooking")
	FCampfireStewStateVector GetPotState() const { return PotState; }

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Cooking")
	FOnCookingStateChanged OnCookingStateChanged;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Cooking")
	FOnMealPrepared OnMealPrepared;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Cooking")
	FOnMealConsumed OnMealConsumed;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Cooking")
	FOnRationSpoiled OnRationSpoiled;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Cooking")
	FCampfireStewStateVector PotState;
};
