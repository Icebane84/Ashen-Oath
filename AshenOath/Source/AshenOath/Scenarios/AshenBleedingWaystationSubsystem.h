// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Scenarios/AshenBleedingWaystationTypes.h"
#include "AshenBleedingWaystationSubsystem.generated.h"

/**
 * UAshenBleedingWaystationSubsystem
 * 
 * Central world subsystem governing the 7-minute replayable micro-scenario and 4-run causal propagation.
 */
UCLASS()
class ASHENOATH_API UAshenBleedingWaystationSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenBleedingWaystationSubsystem();

	/** Initializes a specific run mode (A, B, C, or D) */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Waystation")
	void InitializeRunMode(EWaystationRunMode Mode);

	/** Executes the universal 'Knocked to One Knee' benchmark event */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Waystation")
	void TriggerKnockedToKneeBenchmark();

	UFUNCTION(BlueprintPure, Category = "Ashen|Waystation")
	FWaystationRunContext GetActiveRunContext() const { return CurrentRunContext; }

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Waystation")
	FOnWaystationRunSelected OnWaystationRunSelected;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Waystation")
	FOnKnockedToKneeBenchmarkTriggered OnKnockedToKneeBenchmarkTriggered;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Waystation")
	FOnFormationSpacingShifted OnFormationSpacingShifted;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Waystation")
	FOnCrucibleCombatCompleted OnCrucibleCombatCompleted;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Waystation")
	FWaystationRunContext CurrentRunContext;
};
