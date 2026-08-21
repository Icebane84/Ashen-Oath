// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Scenarios/AshenScenario2SentinelsGambitTypes.h"
#include "AshenScenario2MissionSubsystem.generated.h"

/**
 * UAshenScenario2MissionSubsystem
 * 
 * Central world subsystem orchestrating Scenario 2: The Sentinel's Gambit (Spire of Elders Jailbreak).
 */
UCLASS()
class ASHENOATH_API UAshenScenario2MissionSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenScenario2MissionSubsystem();

	/** Registers a newly deployed trap by Garrett */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Scenario2")
	bool RegisterTrap(const FGarrettTrapPlacementData& NewTrap);

	/** Records enemy AI funneling into the ravine */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Scenario2")
	void RecordEnemyFunneled(const FName& EnemyId);

	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario2")
	int32 GetDeployedTrapCount() const { return DeployedTraps.Num(); }

	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario2")
	int32 GetEnemiesFunneledCount() const { return FunnelContext.EnemiesFunneledIntoRavine; }

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Scenario2")
	FOnTrapDeployed OnTrapDeployed;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Scenario2")
	FOnPathfindingDisrupted OnPathfindingDisrupted;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Scenario2")
	FOnEnemyFunneledToHazard OnEnemyFunneledToHazard;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Scenario2")
	FOnSentinelsGambitCompleted OnSentinelsGambitCompleted;

private:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Scenario2")
	TMap<FName, FGarrettTrapPlacementData> DeployedTraps;

	FAIRavineFunnelContext FunnelContext;
};
