// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Combat/AshenTripartiteResonanceTypes.h"
#include "AshenTripartiteResonanceSubsystem.generated.h"

class UAshenComboChainEvaluatorComponent;
class UAshenDualSenseHapticResonanceComponent;
class UAshenHarmonizedFinisherOrchestratorComponent;

/**
 * UAshenTripartiteResonanceSubsystem
 * 
 * Central world subsystem coordinating Tripartite combo progression,
 * 60 BPM haptic resonance, and 3-person harmonized finishers.
 */
UCLASS()
class ASHENOATH_API UAshenTripartiteResonanceSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenTripartiteResonanceSubsystem();

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	/** Initiates Step 1: Kaelen Heavy Stagger */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Combat|Trio")
	FTripartiteComboState InitiateComboStep1(AActor* TargetActor, float WindowDurationSeconds);

	/** Advances combo to Step 2: Garrett Wire Snare */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Combat|Trio")
	FTripartiteComboState AdvanceComboStep2(bool bGarrettNear);

	/** Advances combo to Step 3: Serafina Holy Burst */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Combat|Trio")
	FTripartiteComboState AdvanceComboStep3(bool bSerafinaNear);

	/** Executes the 3-person Harmonized Finisher */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Combat|Trio")
	bool ExecuteHarmonizedFinisher(AActor* TargetActor, float BaseDamage);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Combat|Trio")
	FOnTripartiteComboPhaseChanged OnTripartiteComboPhaseChanged;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Combat|Trio")
	FOnHarmonizedFinisherExecuted OnHarmonizedFinisherExecuted;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Combat|Trio")
	FOnFellowshipCatharsisTriggered OnFellowshipCatharsisTriggered;

protected:
	UPROPERTY()
	UAshenComboChainEvaluatorComponent* EvaluatorComponent;

	UPROPERTY()
	UAshenDualSenseHapticResonanceComponent* HapticComponent;

	UPROPERTY()
	UAshenHarmonizedFinisherOrchestratorComponent* OrchestratorComponent;
};
