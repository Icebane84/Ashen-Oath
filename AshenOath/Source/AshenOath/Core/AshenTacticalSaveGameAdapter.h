// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Tactics/AshenSquadTacticalTypes.h"
#include "AshenTacticalSaveGameAdapter.generated.h"

/**
 * UAshenTacticalSaveGameAdapter
 * 
 * Serializes custom tactical squad command layouts, wheel presets, and co-op preferences.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTacticalSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenTacticalSaveGameAdapter();

	/** Packages tactical settings for save archive */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	void PackageTacticalSettings(bool bEnableBulletTime, float DilationScale, int32 DefaultSector);

	/** Restores tactical settings from save archive */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	bool RestoreTacticalSettings(bool& OutEnableBulletTime, float& OutDilationScale, int32& OutDefaultSector);

	UFUNCTION(BlueprintPure, Category = "Ashen|Core|SaveGame")
	bool HasSavedData() const { return bHasSavedData; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	bool bSavedEnableBulletTime = true;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	float SavedDilationScale = 0.20f;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	int32 SavedDefaultSector = 0;

private:
	bool bHasSavedData = false;
};
