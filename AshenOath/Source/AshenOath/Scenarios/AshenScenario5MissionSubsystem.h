// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Scenarios/AshenScenario5WeepingMireTypes.h"
#include "AshenScenario5MissionSubsystem.generated.h"

/**
 * UAshenScenario5MissionSubsystem
 * 
 * Central world subsystem orchestrating Scenario 5: The Unchained Vessel (Weeping Mire Skirmish).
 */
UCLASS()
class ASHENOATH_API UAshenScenario5MissionSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenScenario5MissionSubsystem();

	/** Activates Unchained Frenzy phase */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Scenario5")
	void SetUnchainedPhase(EUnchainedVesselPhase NewPhase);

	/** Records volatile swamp gas pocket ignition */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Scenario5")
	void IgniteGasPocket(const FName& PocketId, float Radius);

	/** Triggers companion boundary defense perimeter */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Scenario5")
	void TriggerBoundaryDefense(ECompanionBoundaryDefenseState State, float Radius);

	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario5")
	EUnchainedVesselPhase GetCurrentPhase() const { return CurrentPhase; }

	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario5")
	int32 GetDetonatedGasPocketsCount() const { return Telemetry.GasPocketsDetonated; }

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Scenario5")
	FOnUnchainedPhaseChanged OnUnchainedPhaseChanged;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Scenario5")
	FOnGasPocketIgnited OnGasPocketIgnited;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Scenario5")
	FOnBoundaryDefenseTriggered OnBoundaryDefenseTriggered;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Scenario5")
	FOnWeepingMireCleared OnWeepingMireCleared;

private:
	EUnchainedVesselPhase CurrentPhase = EUnchainedVesselPhase::Dormant;
	FUnchainedCombatTelemetry Telemetry;
};
