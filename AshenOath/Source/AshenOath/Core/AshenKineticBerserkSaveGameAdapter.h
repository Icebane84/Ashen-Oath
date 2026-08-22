// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenKineticBerserkTypes.h"
#include "AshenKineticBerserkSaveGameAdapter.generated.h"

/**
 * UAshenKineticBerserkSaveGameAdapter
 * 
 * Serializes and restores kinetic combat metrics, perfect angular ripostes, and max kinetic Joules.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenKineticBerserkSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenKineticBerserkSaveGameAdapter();

	/** Packages kinetic combat telemetry for save game */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	void PackageKineticStats(int32 TotalRipostes, float MaxRecordedJoules, int32 StructuralFractures);

	/** Restores kinetic combat telemetry from save game */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	bool RestoreKineticStats(int32& OutTotalRipostes, float& OutMaxRecordedJoules, int32& OutStructuralFractures);

	UFUNCTION(BlueprintPure, Category = "Ashen|Core|SaveGame")
	bool HasSavedData() const { return bHasSavedData; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	int32 SavedTotalRipostes = 0;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	float SavedMaxRecordedJoules = 0.0f;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	int32 SavedStructuralFractures = 0;

private:
	bool bHasSavedData = false;
};
