// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenCampfireHearthTypes.h"
#include "AshenCampfireSaveGameAdapter.generated.h"

/**
 * UAshenCampfireSaveGameAdapter
 * 
 * Serializes and restores campfire rest history, unlocked traits, and journal stats.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCampfireSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCampfireSaveGameAdapter();

	/** Packages campfire data for save archive */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	void PackageCampfireData(int32 TotalRests, int32 UnlockedTraits, int32 DiscoveredNotes);

	/** Restores campfire data from save archive */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	bool RestoreCampfireData(int32& OutTotalRests, int32& OutUnlockedTraits, int32& OutDiscoveredNotes);

	UFUNCTION(BlueprintPure, Category = "Ashen|Core|SaveGame")
	bool HasSavedData() const { return bHasSavedData; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	int32 SavedTotalRests = 0;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	int32 SavedUnlockedTraits = 0;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	int32 SavedDiscoveredNotes = 0;

private:
	bool bHasSavedData = false;
};
