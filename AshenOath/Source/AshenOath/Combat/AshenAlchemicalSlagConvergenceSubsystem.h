// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Combat/AshenAlchemicalSlagTypes.h"
#include "AshenAlchemicalSlagConvergenceSubsystem.generated.h"

/**
 * UAshenAlchemicalSlagConvergenceSubsystem
 * 
 * Central world subsystem orchestrating Oathbringer's soot battery accumulation, Garrett's alchemical weapon coatings, and battlefield thermal reactions.
 */
UCLASS()
class ASHENOATH_API UAshenAlchemicalSlagConvergenceSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenAlchemicalSlagConvergenceSubsystem();

	/** Adds soot from combat strikes or beast kills */
	UFUNCTION(BlueprintCallable, Category = "Ashen|AlchemicalSlag")
	void AddSoot(float DeltaSoot);

	/** Applies an alchemical coating to Oathbringer */
	UFUNCTION(BlueprintCallable, Category = "Ashen|AlchemicalSlag")
	void ApplyCoating(EAlchemicalBladeCoating NewCoating, int32 Charges = 5);

	/** Cleanses soot at a campfire restoring the Resolve state */
	UFUNCTION(BlueprintCallable, Category = "Ashen|AlchemicalSlag")
	void PolishBladeAtCampfire();

	/** Evaluates and triggers thermal/chemical reactions upon landing a hit */
	UFUNCTION(BlueprintCallable, Category = "Ashen|AlchemicalSlag")
	FThermalReactionResult ProcessHitReaction(bool bTargetIsChilled, bool bTargetInAcidRain, bool bTargetInLightningStorm);

	UFUNCTION(BlueprintPure, Category = "Ashen|AlchemicalSlag")
	float GetSootLevel() const { return BladeVector.SootLevel; }

	UFUNCTION(BlueprintPure, Category = "Ashen|AlchemicalSlag")
	EOathbringerBladeSurfaceState GetSurfaceState() const { return BladeVector.SurfaceState; }

	UFUNCTION(BlueprintPure, Category = "Ashen|AlchemicalSlag")
	EAlchemicalBladeCoating GetActiveCoating() const { return BladeVector.ActiveCoating; }

	UFUNCTION(BlueprintPure, Category = "Ashen|AlchemicalSlag")
	int32 GetRemainingCharges() const { return BladeVector.RemainingCoatingCharges; }

	UPROPERTY(BlueprintAssignable, Category = "Ashen|AlchemicalSlag")
	FOnBladeSootLevelChanged OnBladeSootLevelChanged;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|AlchemicalSlag")
	FOnAlchemicalCoatingApplied OnAlchemicalCoatingApplied;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|AlchemicalSlag")
	FOnThermalReactionTriggered OnThermalReactionTriggered;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|AlchemicalSlag")
	FOnBladePolishedAtCampfire OnBladePolishedAtCampfire;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|AlchemicalSlag")
	FBladeSootCoatingVector BladeVector;

private:
	void UpdateSurfaceState();
};
