// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Combat/AshenCombatKinematicsTypes.h"
#include "AshenCombatKinematicsConvergenceSubsystem.generated.h"

/**
 * UAshenCombatKinematicsConvergenceSubsystem
 * 
 * Central world subsystem orchestrating the 4-way feedback loop between equipment weight classes, cardiac stamina exhaustion, poise break hitstops, and perfect deflection surges.
 */
UCLASS()
class ASHENOATH_API UAshenCombatKinematicsConvergenceSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenCombatKinematicsConvergenceSubsystem();

	/** Updates real-time combat kinematics state */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Kinematics")
	void UpdateKinematicsState(float CurrentWeightKg, float MaxLoadKg, float CurrentStaminaPercent, float CurrentPoisePercent);

	/** Triggers global Poise-Break hitstop time dilation */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Kinematics")
	void TriggerPoiseBreakHitstop(AActor* TargetActor);

	/** Triggers Perfect Parry White Flame surge */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Kinematics")
	void TriggerPerfectParrySurge();

	UFUNCTION(BlueprintPure, Category = "Ashen|Kinematics")
	FCombatKinematicsVector GetKinematicsState() const { return KinematicsState; }

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Kinematics")
	FOnWeightClassChanged OnWeightClassChanged;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Kinematics")
	FOnCardiacExhaustionToggled OnCardiacExhaustionToggled;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Kinematics")
	FOnPoiseBreakTriggered OnPoiseBreakTriggered;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Kinematics")
	FOnPerfectParrySurgeTriggered OnPerfectParrySurgeTriggered;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Kinematics")
	FCombatKinematicsVector KinematicsState;
};
