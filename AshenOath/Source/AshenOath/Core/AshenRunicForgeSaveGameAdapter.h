// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenRunicForgeTypes.h"
#include "Crafting/AshenRunicReliquaryTypes.h"
#include "AshenRunicForgeSaveGameAdapter.generated.h"

/**
 * UAshenRunicForgeSaveGameAdapter
 * 
 * Serializes Oathbringer's ascension tier, 4 guard socketed sigils, and legacy soul forge states into SaveGame archives.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenRunicForgeSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenRunicForgeSaveGameAdapter();

	/** Packages forge state for SaveGame */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	void PackageForgeState(EOathbringerAscensionTier Tier, ESigilResonanceEffect VomTagSigil, ESigilResonanceEffect PflugSigil);

	/** Restores forge state from SaveGame */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	bool RestoreForgeState(EOathbringerAscensionTier& OutTier, ESigilResonanceEffect& OutVomTag, ESigilResonanceEffect& OutPflug);

	/** Packages legacy soul forge weapon state */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	void PackageWeaponState(const FSoulForgeWeaponState& State);

	/** Restores legacy soul forge weapon state */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	bool RestoreWeaponState(FSoulForgeWeaponState& OutState);

	UFUNCTION(BlueprintPure, Category = "Ashen|Core|SaveGame")
	bool HasSavedData() const { return bHasSavedData; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	EOathbringerAscensionTier SavedTier = EOathbringerAscensionTier::Tier1_DullNightsteel;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	ESigilResonanceEffect SavedVomTag = ESigilResonanceEffect::None;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	ESigilResonanceEffect SavedPflug = ESigilResonanceEffect::None;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	FSoulForgeWeaponState SavedWeaponState;

private:
	bool bHasSavedData = false;
};
