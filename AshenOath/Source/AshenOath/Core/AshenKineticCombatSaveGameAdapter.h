// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenMassKineticTypes.h"
#include "AshenKineticCombatSaveGameAdapter.generated.h"

/**
 * UAshenKineticCombatSaveGameAdapter
 * 
 * Serializes kinetic destruction statistics and berserk state usage metrics.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenKineticCombatSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenKineticCombatSaveGameAdapter();

	/** Packages kinetic combat stats for save archive */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	void PackageKineticData(int32 DestroyedPillarsCount, float PeakKineticJoules, int32 SuccessfulParries);

	/** Restores kinetic combat stats from save archive */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	bool RestoreKineticData(int32& OutDestroyedPillars, float& OutPeakKineticJoules, int32& OutSuccessfulParries);

	UFUNCTION(BlueprintPure, Category = "Ashen|Core|SaveGame")
	bool HasSavedData() const { return bHasSavedData; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	int32 SavedDestroyedPillars = 0;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	float SavedPeakJoules = 0.0f;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	int32 SavedParries = 0;

private:
	bool bHasSavedData = false;
};
