// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenBladeSanityConductorTypes.h"
#include "AshenBladeSanitySaveGameAdapter.generated.h"

/**
 * UAshenBladeSanitySaveGameAdapter
 * 
 * Serializes Oathbringer blade hunger, sanity level, and audio dissonance state into persistent SaveGame files.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenBladeSanitySaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenBladeSanitySaveGameAdapter();

	/** Packages convergence state for SaveGame */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	void PackageConvergenceState(float BladeHunger01, float CurrentSanity, ESanityDissonanceTier DissonanceTier);

	/** Restores convergence state from SaveGame */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	bool RestoreConvergenceState(float& OutBladeHunger01, float& OutCurrentSanity, ESanityDissonanceTier& OutDissonanceTier);

	UFUNCTION(BlueprintPure, Category = "Ashen|Core|SaveGame")
	bool HasSavedData() const { return bHasSavedData; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	float SavedBladeHunger01 = 0.0f;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	float SavedCurrentSanity = 100.0f;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	ESanityDissonanceTier SavedDissonanceTier = ESanityDissonanceTier::LucidHarmonic;

private:
	bool bHasSavedData = false;
};
