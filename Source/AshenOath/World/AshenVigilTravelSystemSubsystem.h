// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenVigilTravelSystemSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnVigilanceLevelChangedSignature, float, NewVigilanceLevel, bool, bIsPartyExhausted);

/**
 * UAshenVigilTravelSystemSubsystem
 *
 * World Subsystem governing strategic travel readiness and Vigilance meter tracking during journeys between sanctuaries.
 */
UCLASS()
class ASHENOATH_API UAshenVigilTravelSystemSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|VigilTravel")
	void ConsumeVigilanceDuringTravel(float DistanceTravelled);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|VigilTravel")
	void RestAtSanctuaryRestoreVigilance();

	UFUNCTION(BlueprintPure, Category = "AshenOath|VigilTravel")
	float GetVigilanceLevel() const { return CurrentVigilance; }

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|VigilTravel|Events")
	FOnVigilanceLevelChangedSignature OnVigilanceLevelChanged;

private:
	float CurrentVigilance = 100.0f;
};
