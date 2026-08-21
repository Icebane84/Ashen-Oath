// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Crafting/AshenRunicReliquaryTypes.h"
#include "AshenRunicForgeSaveGameAdapter.generated.h"

/**
 * UAshenRunicForgeSaveGameAdapter
 * 
 * Serializes and restores socketed weapon states, active mass configurations,
 * and boss core infusions.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenRunicForgeSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenRunicForgeSaveGameAdapter();

	/** Packages weapon state for save file */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	void PackageWeaponState(const FSoulForgeWeaponState& State);

	/** Restores weapon state from save archive */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	bool RestoreWeaponState(FSoulForgeWeaponState& OutState);

	UFUNCTION(BlueprintPure, Category = "Ashen|Core|SaveGame")
	bool HasSavedData() const { return bHasSavedData; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	FSoulForgeWeaponState SavedState;

private:
	bool bHasSavedData = false;
};
