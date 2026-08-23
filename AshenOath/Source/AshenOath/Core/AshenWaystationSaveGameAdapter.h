// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenBleedingWaystationTypes.h"
#include "AshenWaystationSaveGameAdapter.generated.h"

/**
 * UAshenWaystationSaveGameAdapter
 * 
 * Serializes and restores 4-run crucible metrics, catalyst decisions, and companion formation distances.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenWaystationSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenWaystationSaveGameAdapter();

	/** Packages waystation state for save game file */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	void PackageWaystationState(EWaystationRunMode Mode, EScoutCatalystDecision Decision, float SerafinaDist, float HesitationMS);

	/** Restores waystation state from save game file */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	bool RestoreWaystationState(EWaystationRunMode& OutMode, EScoutCatalystDecision& OutDecision, float& OutSerafinaDist, float& OutHesitationMS);

	UFUNCTION(BlueprintPure, Category = "Ashen|Core|SaveGame")
	bool HasSavedData() const { return bHasSavedData; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	EWaystationRunMode SavedRunMode = EWaystationRunMode::RunA_ShadowHarvest;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	EScoutCatalystDecision SavedDecision = EScoutCatalystDecision::HarvestResidualTaint;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	float SavedSerafinaDistance = 1000.0f;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	float SavedHesitationMS = 300.0f;

private:
	bool bHasSavedData = false;
};
