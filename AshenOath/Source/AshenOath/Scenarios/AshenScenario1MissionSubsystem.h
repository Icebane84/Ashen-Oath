// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Scenarios/AshenScenario1CauterizedHeartTypes.h"
#include "AshenScenario1MissionSubsystem.generated.h"

/**
 * UAshenScenario1MissionSubsystem
 * 
 * Central world subsystem orchestrating Scenario 1: The Cauterized Heart (Oakhaven Chapel).
 */
UCLASS()
class ASHENOATH_API UAshenScenario1MissionSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenScenario1MissionSubsystem();

	/** Updates the active Malakor boss encounter state */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Scenario1")
	void UpdateEncounterState(const FMalakorEncounterState& NewState);

	/** Handles ritual progress and disruption events */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Scenario1")
	void ProcessRitualDisruption(float CurrentProgress, float DebtSpike);

	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario1")
	FMalakorEncounterState GetEncounterState() const { return EncounterState; }

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Scenario1")
	FOnMalakorPhaseShifted OnMalakorPhaseShifted;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Scenario1")
	FOnRitualInterrupted OnRitualInterrupted;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Scenario1")
	FOnReluctantKnifeEvaluated OnReluctantKnifeEvaluated;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Scenario1")
	FOnOakhavenChapelCleared OnOakhavenChapelCleared;

private:
	FMalakorEncounterState EncounterState;
};
