// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Companions/AshenTripartiteCognitiveLoopTypes.h"
#include "AshenTripartiteSaveGameAdapter.generated.h"

/**
 * UAshenTripartiteSaveGameAdapter
 * 
 * Serializes and restores tripartite attunement score, active mode, silence contract, and historical finisher metrics.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTripartiteSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenTripartiteSaveGameAdapter();

	// --- Batch #120 API ---
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	void PackageTripartiteData(int32 TotalFinishers, int32 UnbrokenStreaks, float CatharsisScore);

	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	bool RestoreTripartiteData(int32& OutFinishers, int32& OutStreaks, float& OutCatharsis);

	// --- Batch #134 API ---
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	void PackageTripartiteState(float AttunementScore, ETripartiteBehaviorMode Mode, bool bSilenceMaintained);

	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	bool RestoreTripartiteState(float& OutAttunementScore, ETripartiteBehaviorMode& OutMode, bool& OutSilenceMaintained);

	UFUNCTION(BlueprintPure, Category = "Ashen|Core|SaveGame")
	bool HasSavedData() const { return bHasSavedData; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	int32 SavedTotalFinishers = 0;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	int32 SavedUnbrokenStreaks = 0;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	float SavedCatharsisScore = 0.0f;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	float SavedAttunementScore = 0.50f;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	ETripartiteBehaviorMode SavedMode = ETripartiteBehaviorMode::CombatEngagement;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	bool bSavedSilenceMaintained = true;

private:
	bool bHasSavedData = false;
};
