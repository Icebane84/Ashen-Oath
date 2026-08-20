// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenFugitivesNetworkHostilitySubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnOrderHostilityLevelChangedSignature, FName, RegionID, float, HostilityLevel);

/**
 * UAshenFugitivesNetworkHostilitySubsystem
 *
 * World Subsystem managing regional Order of the White Flame Hostility levels and cultivating fugitive network allies.
 */
UCLASS()
class ASHENOATH_API UAshenFugitivesNetworkHostilitySubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|FugitivesNetwork")
	void ModifyRegionalHostility(FName RegionID, float HostilityDelta);

	UFUNCTION(BlueprintPure, Category = "AshenOath|FugitivesNetwork")
	float GetRegionalHostility(FName RegionID) const;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|FugitivesNetwork|Events")
	FOnOrderHostilityLevelChangedSignature OnHostilityLevelChanged;

private:
	TMap<FName, float> RegionalHostilityLevels;
};
