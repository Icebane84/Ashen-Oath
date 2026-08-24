// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Scenarios/AshenScenario6Types.h"
#include "AshenScenario6MissionSubsystem.generated.h"

/**
 * UAshenScenario6MissionSubsystem
 * 
 * Central world subsystem managing quest flow, blizzard intensity, and hearth ignition in the Northern Marches.
 */
UCLASS()
class ASHENOATH_API UAshenScenario6MissionSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenScenario6MissionSubsystem();

	/** Updates the active blizzard weather intensity */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Scenario6")
	void SetBlizzardIntensity(EBlizzardIntensity NewIntensity);

	/** Adds thermal ignition progress to the Sanctified Hearth Brazier */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Scenario6")
	void ChannelHearthIgnition(float DeltaProgress);

	/** Updates somatic frostbite accumulation */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Scenario6")
	void ApplyFrostbiteDelta(float DeltaFrostbite, bool bInWarmthZone);

	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario6")
	FSanctifiedHearthStateVector GetCurrentHearthState() const { return CurrentState; }

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Scenario6")
	FOnBlizzardWeatherChanged OnBlizzardWeatherChanged;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Scenario6")
	FOnFrostbiteUpdated OnFrostbiteUpdated;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Scenario6")
	FOnHearthIgnitionProgressChanged OnHearthIgnitionProgressChanged;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Scenario6")
	FOnSanctifiedHearthComplete OnSanctifiedHearthComplete;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Scenario6")
	FSanctifiedHearthStateVector CurrentState;
};
