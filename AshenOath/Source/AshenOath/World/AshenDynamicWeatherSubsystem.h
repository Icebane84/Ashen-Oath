// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "World/AshenDynamicWeatherTypes.h"
#include "AshenDynamicWeatherSubsystem.generated.h"

/**
 * UAshenDynamicWeatherSubsystem
 * 
 * Central world subsystem governing dynamic atmospheric climate shifts, environmental hazard cycles, and biome weather states.
 */
UCLASS()
class ASHENOATH_API UAshenDynamicWeatherSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenDynamicWeatherSubsystem();

	/** Transitions to a new target weather state */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Weather")
	void SetWeatherState(EWeatherHazardState NewState, EAtmosphericSeverity NewSeverity);

	/** Applies weather tick update */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Weather")
	void UpdateWeatherCycle(float DeltaSeconds);

	UFUNCTION(BlueprintPure, Category = "Ashen|Weather")
	FWeatherAtmosphericVector GetAtmosphericState() const { return CurrentAtmosphere; }

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Weather")
	FOnWeatherStateChanged OnWeatherStateChanged;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Weather")
	FOnLightningTelegraphed OnLightningTelegraphed;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Weather")
	FOnShelterStatusChanged OnShelterStatusChanged;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Weather")
	FOnHazardDamageApplied OnHazardDamageApplied;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Weather")
	FWeatherAtmosphericVector CurrentAtmosphere;
};
