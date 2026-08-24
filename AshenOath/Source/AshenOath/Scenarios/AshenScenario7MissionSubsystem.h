// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Scenarios/AshenScenario7Types.h"
#include "AshenScenario7MissionSubsystem.generated.h"

/**
 * UAshenScenario7MissionSubsystem
 * 
 * Central world subsystem governing Scenario 7: The Ashen Crucible, tracking thermodynamics, magma surges, and blade tempering.
 */
UCLASS()
class ASHENOATH_API UAshenScenario7MissionSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenScenario7MissionSubsystem();

	/** Updates the caldera ambient temperature and processes somatic heat exhaustion */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Scenario7")
	void SetCalderaTemperature(float NewTempC, bool bInCoolingZone);

	/** Advances the magma surge eruption state */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Scenario7")
	void AdvanceMagmaSurgePhase(ECalderaSurgePhase NewPhase, const FVector& SurgeLocation);

	/** Updates the blade tempering heat and state */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Scenario7")
	void SetBladeTempering(float BladeTempC, ETemperedBladeState NewState);

	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario7")
	FCalderaThermodynamicsVector GetThermodynamicsState() const { return ThermodynamicsState; }

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Scenario7")
	FOnCalderaTemperatureChanged OnCalderaTemperatureChanged;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Scenario7")
	FOnMagmaSurgeStateChanged OnMagmaSurgeStateChanged;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Scenario7")
	FOnBladeTemperingStateChanged OnBladeTemperingStateChanged;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Scenario7")
	FOnHeatExhaustionTierChanged OnHeatExhaustionTierChanged;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Scenario7")
	FCalderaThermodynamicsVector ThermodynamicsState;
};
