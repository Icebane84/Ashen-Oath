// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "World/AshenSanctuarySurvivalTypes.h"
#include "AshenSanctuarySurvivalConvergenceSubsystem.generated.h"

/**
 * UAshenSanctuarySurvivalConvergenceSubsystem
 * 
 * Central world subsystem orchestrating campfire meal hazard immunities, thermodynamic shelter calculations, and sanctuary beacon journal inscriptions.
 */
UCLASS()
class ASHENOATH_API UAshenSanctuarySurvivalConvergenceSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenSanctuarySurvivalConvergenceSubsystem();

	/** Applies a cooked meal buff granting hazard immunity */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Survival")
	void ApplyMealBuff(ECookedMealBuffType MealType, float DurationSeconds = 900.0f);

	/** Sets current environmental shelter tier */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Survival")
	void SetShelterTier(EThermalShelterTier NewTier);

	/** Discovers and ignites a sanctuary beacon */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Survival")
	void IgniteBeacon(FName BeaconId, const FString& RegionName, const FText& InscribedLore);

	UFUNCTION(BlueprintPure, Category = "Ashen|Survival")
	ECookedMealBuffType GetActiveMeal() const { return ActiveMealData.ActiveMeal; }

	UFUNCTION(BlueprintPure, Category = "Ashen|Survival")
	EThermalShelterTier GetShelterTier() const { return CurrentThermodynamics.ShelterTier; }

	UFUNCTION(BlueprintPure, Category = "Ashen|Survival")
	float GetBodyTemperature() const { return CurrentThermodynamics.BodyTemperatureCelsius; }

	UFUNCTION(BlueprintPure, Category = "Ashen|Survival")
	bool IsBeaconIgnited(FName BeaconId) const;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Survival")
	FOnMealBuffApplied OnMealBuffApplied;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Survival")
	FOnShelterTierChanged OnShelterTierChanged;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Survival")
	FOnSanctuaryBeaconIgnited OnSanctuaryBeaconIgnited;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Survival")
	FOnForensicJournalEntryAutoLogged OnForensicJournalEntryAutoLogged;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Survival")
	FMealHazardImmunityData ActiveMealData;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Survival")
	FShelterThermodynamicState CurrentThermodynamics;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Survival")
	TMap<FName, FSanctuaryBeaconRecord> DiscoveredBeacons;

private:
	void UpdateThermodynamicState();
};
