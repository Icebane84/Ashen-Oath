// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "World/AshenDestructionWeatherAITypes.h"
#include "AshenDestructionWeatherAIConvergenceSubsystem.generated.h"

/**
 * UAshenDestructionWeatherAIConvergenceSubsystem
 * 
 * Central world subsystem orchestrating environmental destruction, dynamic weather perception clamping, conductive lightning arcs, and AI pincer flanking.
 */
UCLASS()
class ASHENOATH_API UAshenDestructionWeatherAIConvergenceSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenDestructionWeatherAIConvergenceSubsystem();

	/** Updates active weather perception bounds */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Convergence")
	void UpdateWeatherPerceptionBounds(EAtmosphericVisibilityTier VisibilityTier);

	/** Triggers conductive chain-lightning discharge */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Convergence")
	void TriggerConductiveLightningArc(FVector Origin, const TArray<FConductiveArcTargetInfo>& PotentialTargets);

	/** Registers newly cleaved rubble obstacle */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Convergence")
	void RegisterCleavedRubbleObstacle(FVector ObstacleLocation, float Radius);

	/** Triggers explosive cover shatter */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Convergence")
	void TriggerCoverShatter(FVector ShatterLocation, float ShrapnelDmg);

	UFUNCTION(BlueprintPure, Category = "Ashen|Convergence")
	FWeatherPerceptionVector GetPerceptionVector() const { return CurrentPerception; }

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Convergence")
	FOnWeatherPerceptionClamped OnWeatherPerceptionClamped;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Convergence")
	FOnConductiveLightningArced OnConductiveLightningArced;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Convergence")
	FOnRubbleChokepointFormed OnRubbleChokepointFormed;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Convergence")
	FOnCoverShattered OnCoverShattered;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Convergence")
	FWeatherPerceptionVector CurrentPerception;
};
