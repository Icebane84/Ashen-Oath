// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenTripartiteResonanceTypes.h"
#include "AshenTripartiteSaveGameAdapter.generated.h"

/**
 * UAshenTripartiteSaveGameAdapter
 * 
 * Serializes and restores Tripartite combo and finisher statistics.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTripartiteSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenTripartiteSaveGameAdapter();

	/** Packages finisher stats for save archive */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	void PackageTripartiteData(int32 TotalFinishers, int32 UnbrokenStreaks, float TotalCatharsisScore);

	/** Restores finisher stats from save archive */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	bool RestoreTripartiteData(int32& OutTotalFinishers, int32& OutUnbrokenStreaks, float& OutTotalCatharsisScore);

	UFUNCTION(BlueprintPure, Category = "Ashen|Core|SaveGame")
	bool HasSavedData() const { return bHasSavedData; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	int32 SavedTotalFinishers = 0;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	int32 SavedUnbrokenStreaks = 0;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	float SavedCatharsisScore = 0.0f;

private:
	bool bHasSavedData = false;
};
