// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Narrative/AshenCampfireHearthTypes.h"
#include "AshenCampfireHearthSubsystem.generated.h"

class UAshenSoulRecoveryEvaluatorComponent;
class UAshenProximitySeatingStagingComponent;
class UAshenTraumaTransmutationEngineComponent;

/**
 * UAshenCampfireHearthSubsystem
 * 
 * Central world subsystem coordinating campfire rest sessions, companion
 * proximity seating, and trauma integration into permanent traits.
 */
UCLASS()
class ASHENOATH_API UAshenCampfireHearthSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenCampfireHearthSubsystem();

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	/** Initiates a campfire rest session */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Narrative|Hearth")
	FCampfireIntegrationSnapshot BeginRestSession(float CurrentDebt, float CurrentDysregulation);

	/** Computes companion seating position around the hearth */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Narrative|Hearth")
	ECompanionHearthSeating EvaluateCompanionSeating(FName CompanionName, float Trust, float Dysregulation);

	/** Transmutes accumulated trauma into a permanent trait */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Narrative|Hearth")
	FTransmutedTraitReward TransmuteTraumaToTrait(FName TraitName, FGameplayTag TraitTag, float Bonus);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Narrative|Hearth")
	FOnCampfireRestStarted OnCampfireRestStarted;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Narrative|Hearth")
	FOnTraumaTransmuted OnTraumaTransmuted;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Narrative|Hearth")
	FOnCompanionSeatingStaged OnCompanionSeatingStaged;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Narrative|Hearth")
	FOnSolemnVigilCompleted OnSolemnVigilCompleted;

protected:
	UPROPERTY()
	UAshenSoulRecoveryEvaluatorComponent* RecoveryEvaluator;

	UPROPERTY()
	UAshenProximitySeatingStagingComponent* SeatingStager;

	UPROPERTY()
	UAshenTraumaTransmutationEngineComponent* TransmutationEngine;
};
