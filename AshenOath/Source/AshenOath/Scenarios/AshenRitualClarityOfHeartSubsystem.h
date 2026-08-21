// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Scenarios/AshenScenario1CauterizedHeartTypes.h"
#include "AshenRitualClarityOfHeartSubsystem.generated.h"

/**
 * UAshenRitualClarityOfHeartSubsystem
 * 
 * Tracks the Clarity of Heart ritual completion and calculates debt penalties on disruption.
 */
UCLASS()
class ASHENOATH_API UAshenRitualClarityOfHeartSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenRitualClarityOfHeartSubsystem();

	/** Advances ritual progress and returns completion state */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Scenario1|Ritual")
	bool AdvanceRitual(float DeltaProgress);

	/** Computes IntegrationDebt spike caused by Malakor breaking the ritual */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario1|Ritual")
	float EvaluateDebtSpikeOnInterruption(float ProgressAtInterrupt) const;

	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario1|Ritual")
	float GetRitualProgress() const { return RitualContext.RitualProgressPercent; }

private:
	FClarityOfHeartRitualContext RitualContext;
};
