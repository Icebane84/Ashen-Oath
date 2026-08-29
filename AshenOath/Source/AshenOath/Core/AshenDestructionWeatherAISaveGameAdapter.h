// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenDestructionWeatherAITypes.h"
#include "AshenDestructionWeatherAISaveGameAdapter.generated.h"

/**
 * UAshenDestructionWeatherAISaveGameAdapter
 * 
 * Serializes collapsed environmental chokepoints, active weather visibility calibration, and tactical threat maps into SaveGame files.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDestructionWeatherAISaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDestructionWeatherAISaveGameAdapter();

	/** Packages tactical convergence state for SaveGame */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	void PackageTacticalState(EAtmosphericVisibilityTier VisibilityTier, float LockOnRangeUU, int32 CleavedObstacleCount);

	/** Restores tactical convergence state from SaveGame */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	bool RestoreTacticalState(EAtmosphericVisibilityTier& OutTier, float& OutLockOnRangeUU, int32& OutObstacleCount);

	UFUNCTION(BlueprintPure, Category = "Ashen|Core|SaveGame")
	bool HasSavedData() const { return bHasSavedData; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	EAtmosphericVisibilityTier SavedTier = EAtmosphericVisibilityTier::ClearDaylight;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	float SavedLockOnRangeUU = 1500.0f;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	int32 SavedObstacleCount = 0;

private:
	bool bHasSavedData = false;
};
