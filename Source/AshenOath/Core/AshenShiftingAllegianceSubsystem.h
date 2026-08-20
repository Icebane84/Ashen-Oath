// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenShiftingAllegianceSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTerritoryControlShiftedSignature, FName, RegionID, FName, ControllingFactionID);

/**
 * UAshenShiftingAllegianceSubsystem
 *
 * World Subsystem tracking dynamic faction war shifts and regional territorial control.
 */
UCLASS()
class ASHENOATH_API UAshenShiftingAllegianceSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|ShiftingAllegiance")
	void ShiftTerritoryControl(FName RegionID, FName NewControllingFactionID);

	UFUNCTION(BlueprintPure, Category = "AshenOath|ShiftingAllegiance")
	FName GetControllingFaction(FName RegionID) const;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|ShiftingAllegiance|Events")
	FOnTerritoryControlShiftedSignature OnTerritoryControlShifted;

private:
	TMap<FName, FName> TerritoryControlMap;
};
