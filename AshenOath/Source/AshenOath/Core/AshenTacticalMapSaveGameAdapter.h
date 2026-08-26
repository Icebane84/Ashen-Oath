// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenTacticalMapTypes.h"
#include "AshenTacticalMapSaveGameAdapter.generated.h"

/**
 * UAshenTacticalMapSaveGameAdapter
 * 
 * Serializes discovered beacons, attuned sanctuary waypoints, and unveiled fog-of-war exploration maps into save files.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTacticalMapSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenTacticalMapSaveGameAdapter();

	/** Packages map state for SaveGame */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	void PackageMapState(const FString& CurrentSanctuary, int32 DiscoveredCount, int32 AttunedCount);

	/** Restores map state from SaveGame */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	bool RestoreMapState(FString& OutCurrentSanctuary, int32& OutDiscoveredCount, int32& OutAttunedCount);

	UFUNCTION(BlueprintPure, Category = "Ashen|Core|SaveGame")
	bool HasSavedData() const { return bHasSavedData; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	FString SavedCurrentSanctuary = TEXT("Waypoint_Hearth_01");

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	int32 SavedDiscoveredCount = 1;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	int32 SavedAttunedCount = 1;

private:
	bool bHasSavedData = false;
};
