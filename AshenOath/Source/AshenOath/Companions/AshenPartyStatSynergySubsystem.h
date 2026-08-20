// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenPartyStatSynergySubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPartySynergyUpdatedSignature, float, SynergyMultiplier, int32, ActiveCompanionsInProximity);

/**
 * UAshenPartyStatSynergySubsystem
 *
 * World Subsystem calculating cross-companion stat synergies when Kaelen, Garrett, and Serafina fight in proximity.
 */
UCLASS()
class ASHENOATH_API UAshenPartyStatSynergySubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|PartySynergy")
	float EvaluatePartyProximitySynergy(AActor* KaelenActor, float ProximityRadius = 800.0f);

	UFUNCTION(BlueprintPure, Category = "AshenOath|PartySynergy")
	float GetActiveSynergyMultiplier() const { return CurrentSynergyMultiplier; }

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|PartySynergy|Events")
	FOnPartySynergyUpdatedSignature OnPartySynergyUpdated;

private:
	float CurrentSynergyMultiplier = 1.0f;
};
