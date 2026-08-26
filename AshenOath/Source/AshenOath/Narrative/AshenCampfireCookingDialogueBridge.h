// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenCampfireCookingTypes.h"
#include "AshenCampfireCookingDialogueBridge.generated.h"

/**
 * UAshenCampfireCookingDialogueBridge
 * 
 * Generates contextual companion banter and culinary reflections around the campfire pot.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCampfireCookingDialogueBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCampfireCookingDialogueBridge();

	/** Formats dialogue bark for meal preparation and consumption */
	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|Cooking")
	FText FormatCookingBark(ECampfireRecipeType Recipe, ECookingPotState PotState) const;
};
