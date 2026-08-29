// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Combat/AshenOathbringerStanceTypes.h"
#include "AshenOathbringerStanceFlowConvergenceSubsystem.generated.h"

/**
 * UAshenOathbringerStanceFlowConvergenceSubsystem
 * 
 * Central world subsystem orchestrating Oathbringer's 4 historical greatsword guards, stamina-neutral recovery flow cancels, and runic fuller seam color transitions.
 */
UCLASS()
class ASHENOATH_API UAshenOathbringerStanceFlowConvergenceSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenOathbringerStanceFlowConvergenceSubsystem();

	/** Switches active Oathbringer greatsword guard */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Oathbringer|Stance")
	void SwitchStance(EOathbringerMartialStance NewStance);

	/** Attempts to execute a rhythm flow cancel during recovery */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Oathbringer|Stance")
	EFlowChainingTimingQuality AttemptFlowCancel(EOathbringerMartialStance TargetStance, float CurrentRecoveryElapsedSeconds);

	/** Sets active recovery flow window */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Oathbringer|Stance")
	void OpenFlowGlintWindow(float StartTimeSeconds, float DurationSeconds);

	UFUNCTION(BlueprintPure, Category = "Ashen|Oathbringer|Stance")
	EOathbringerMartialStance GetCurrentStance() const { return CurrentStance; }

	UFUNCTION(BlueprintPure, Category = "Ashen|Oathbringer|Stance")
	FOathbringerStanceKinematics GetCurrentKinematics() const { return CurrentKinematics; }

	UFUNCTION(BlueprintPure, Category = "Ashen|Oathbringer|Stance")
	float GetCurrentFlowCharge() const { return FlowWindowData.CurrentFlowCharge; }

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Oathbringer|Stance")
	FOnOathbringerStanceChanged OnOathbringerStanceChanged;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Oathbringer|Stance")
	FOnFlowChainingGlintTriggered OnFlowChainingGlintTriggered;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Oathbringer|Stance")
	FOnRunicSeamColorUpdated OnRunicSeamColorUpdated;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Oathbringer|Stance")
	FOnCounterBindParryLanded OnCounterBindParryLanded;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Oathbringer|Stance")
	EOathbringerMartialStance CurrentStance = EOathbringerMartialStance::VomTag_HighWrath;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Oathbringer|Stance")
	FOathbringerStanceKinematics CurrentKinematics;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Oathbringer|Stance")
	FFlowChainingWindowData FlowWindowData;

private:
	void UpdateKinematicsForStance(EOathbringerMartialStance Stance);
};
