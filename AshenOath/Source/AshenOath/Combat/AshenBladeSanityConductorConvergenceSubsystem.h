// Copyright Ashen Oath Tactical RPG. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Combat/AshenBladeSanityConductorTypes.h"
#include "Combat/AshenBladeSanityBalanceDataAsset.h"
#include "AshenBladeSanityConductorConvergenceSubsystem.generated.h"

/**
 * UAshenBladeSanityConductorConvergenceSubsystem
 * 
 * Central world subsystem orchestrating the 4-way feedback loop between Oathbringer blade hunger,
 * sanity collapse, Quartz music stems, and flow state purges (CONVERGENCE-SPEC-090).
 */
UCLASS()
class ASHENOATH_API UAshenBladeSanityConductorConvergenceSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenBladeSanityConductorConvergenceSubsystem();

	/** Updates blade hunger and ticks sanity / audio stem convergence */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Convergence")
	void UpdateConvergenceState(float DeltaSeconds, float NewHunger01, bool bInFlowState);

	/** Purges mental dissonance via Flow State catharsis */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Convergence")
	void TriggerFlowCatharsisPurge();

	UFUNCTION(BlueprintPure, Category = "Ashen|Convergence")
	FBladeSanityHarmonicVector GetHarmonicState() const { return CurrentHarmonics; }

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Convergence")
	FOnBladeHungerSanityShifted OnBladeHungerSanityShifted;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Convergence")
	FOnDissonanceStemGainUpdated OnDissonanceStemGainUpdated;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Convergence")
	FOnFlowCatharsisTriggered OnFlowCatharsisTriggered;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Convergence")
	FOnSanityDissonanceTierChanged OnSanityDissonanceTierChanged;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Convergence|Balancing")
	UAshenBladeSanityBalanceDataAsset* BalanceDataAsset;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Convergence")
	FBladeSanityHarmonicVector CurrentHarmonics;
};
