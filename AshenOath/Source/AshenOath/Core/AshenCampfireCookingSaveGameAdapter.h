// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenCampfireCookingTypes.h"
#include "AshenCampfireCookingSaveGameAdapter.generated.h"

/**
 * UAshenCampfireCookingSaveGameAdapter
 * 
 * Serializes culinary ration inventory, active meal buffs, and unlocked campfire recipes into persistent save files.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCampfireCookingSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCampfireCookingSaveGameAdapter();

	/** Packages cooking state for SaveGame */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	void PackageCookingState(ECampfireRecipeType ActiveMeal, float BuffTimeRemaining, int32 RationsCount);

	/** Restores cooking state from SaveGame */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	bool RestoreCookingState(ECampfireRecipeType& OutActiveMeal, float& OutBuffTimeRemaining, int32& OutRationsCount);

	UFUNCTION(BlueprintPure, Category = "Ashen|Core|SaveGame")
	bool HasSavedData() const { return bHasSavedData; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	ECampfireRecipeType SavedActiveMeal = ECampfireRecipeType::None;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	float SavedBuffTimeRemaining = 0.0f;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	int32 SavedRationsCount = 0;

private:
	bool bHasSavedData = false;
};
