// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Scenarios/AshenScenario8Types.h"
#include "AshenScenario8MissionSubsystem.generated.h"

/**
 * UAshenScenario8MissionSubsystem
 * 
 * Central world subsystem governing Scenario 8: The Searing Abyss, tracking torch endurance, catacomb darkness, and sonar pings.
 */
UCLASS()
class ASHENOATH_API UAshenScenario8MissionSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenScenario8MissionSubsystem();

	/** Updates torch fuel percentage and recomputes effective illumination radius */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Scenario8")
	void SetTorchFuel(float NewFuel01, bool bFlareActive);

	/** Emits an acoustic echolocation ping propagating through the darkness */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Scenario8")
	void EmitEcholocationPing(EEcholocationPulseType PulseType, const FVector& Origin);

	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario8")
	FAbyssDarknessVector GetDarknessState() const { return DarknessState; }

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Scenario8")
	FOnTorchFuelChanged OnTorchFuelChanged;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Scenario8")
	FOnEcholocationPingEmitted OnEcholocationPingEmitted;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Scenario8")
	FOnLightEnvironmentChanged OnLightEnvironmentChanged;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Scenario8")
	FOnRadiantFlareTriggered OnRadiantFlareTriggered;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Scenario8")
	FAbyssDarknessVector DarknessState;
};
