// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Scenarios/AshenScenario9Types.h"
#include "AshenScenario9MissionSubsystem.generated.h"

/**
 * UAshenScenario9MissionSubsystem
 * 
 * Central world subsystem governing Scenario 9: The Whispering Citadel, tracking void gravity scales, wind shear cycles, and bridge integrity.
 */
UCLASS()
class ASHENOATH_API UAshenScenario9MissionSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenScenario9MissionSubsystem();

	/** Sets the active void gravity zone tier */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Scenario9")
	void SetGravityTier(EVoidGravityZoneTier NewTier);

	/** Sets atmospheric wind shear gust speed and direction */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Scenario9")
	void SetWindShearGust(EWindShearGustState State, float SpeedMps, const FVector& Direction);

	/** Updates telekinetic bridge stability status */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Scenario9")
	void SetBridgeStatus(ETelekineticBridgeStatus Status, float Stability01);

	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario9")
	FWhisperingCitadelVector GetCitadelState() const { return CitadelState; }

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Scenario9")
	FOnGravityZoneChanged OnGravityZoneChanged;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Scenario9")
	FOnWindShearGustTriggered OnWindShearGustTriggered;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Scenario9")
	FOnTelekineticBridgeStateChanged OnTelekineticBridgeStateChanged;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Scenario9")
	FOnGravitonCleaveExecuted OnGravitonCleaveExecuted;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Scenario9")
	FWhisperingCitadelVector CitadelState;
};
