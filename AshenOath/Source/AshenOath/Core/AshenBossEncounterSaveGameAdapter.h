// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenBossArenaTypes.h"
#include "AshenBossEncounterSaveGameAdapter.generated.h"

/**
 * UAshenBossEncounterSaveGameAdapter
 * 
 * Serializes and restores boss encounter completion status, phase clear stats,
 * and companion crisis rescue history.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenBossEncounterSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenBossEncounterSaveGameAdapter();

	/** Packages boss encounter data for save archive */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	void PackageBossData(bool bDefeated, int32 PillarsSundered, int32 RescuesPerformed);

	/** Restores boss encounter data from save archive */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	bool RestoreBossData(bool& OutDefeated, int32& OutPillarsSundered, int32& OutRescuesPerformed);

	UFUNCTION(BlueprintPure, Category = "Ashen|Core|SaveGame")
	bool HasSavedData() const { return bHasSavedData; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	bool bSavedDefeated = false;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	int32 SavedPillarsSundered = 0;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	int32 SavedRescuesPerformed = 0;

private:
	bool bHasSavedData = false;
};
