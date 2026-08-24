// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Scenarios/AshenScenario10Types.h"
#include "AshenScenario10MissionSubsystem.generated.h"

/**
 * UAshenScenario10MissionSubsystem
 * 
 * Central world subsystem governing Scenario 10: The Sovereign Convergence, tracking apotheosis buildup, tri-soul resonance, and resolving final consequence endings.
 */
UCLASS()
class ASHENOATH_API UAshenScenario10MissionSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenScenario10MissionSubsystem();

	/** Sets the current apotheosis resonance buildup percentage [0.0 to 1.0] */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Scenario10")
	void SetApotheosisResonance(float Resonance01);

	/** Resolves the Grand Consequence Ending based on party metrics */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Scenario10")
	EZenithConsequenceEnding ResolveFinalConsequence(float TrustScore01, float Debt01, bool bBerserkDominant);

	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario10")
	FZenithConvergenceVector GetConvergenceState() const { return ConvergenceState; }

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Scenario10")
	FOnApotheosisStageChanged OnApotheosisStageChanged;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Scenario10")
	FOnConsequenceEndingResolved OnConsequenceEndingResolved;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Scenario10")
	FOnTripartiteFinisherExecuted OnTripartiteFinisherExecuted;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Scenario10")
	FOnGrandZenithAuraIgnited OnGrandZenithAuraIgnited;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Scenario10")
	FZenithConvergenceVector ConvergenceState;
};
