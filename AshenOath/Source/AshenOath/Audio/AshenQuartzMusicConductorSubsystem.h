// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Audio/AshenQuartzAudioTypes.h"
#include "AshenQuartzMusicConductorSubsystem.generated.h"

/**
 * UAshenQuartzMusicConductorSubsystem
 * 
 * Central world subsystem governing the Quartz 6-stem interactive combat score, downbeat quantization (115 BPM), and flow state transitions.
 */
UCLASS()
class ASHENOATH_API UAshenQuartzMusicConductorSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenQuartzMusicConductorSubsystem();

	/** Updates the 6-stem gains based on Kaelen's Corruption and Serafina's Burnout */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Audio|Quartz")
	void UpdateCombatStemMatrix(float Corruption01, float Burnout01);

	/** Triggers the 8-second Symbiotic Resonance Flow State */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Audio|Quartz")
	void TriggerSymbioticResonance(float DurationSeconds);

	/** Applies an alchemical filter override to the sub-mix */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Audio|Quartz")
	void ApplyAlchemicalFilter(EAlchemicalAudioFilter Filter, float DurationSeconds);

	/** Simulates a Quartz bar downbeat event (115 BPM) */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Audio|Quartz")
	void DispatchBarDownbeat(int32 BarIndex);

	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|Quartz")
	FQuartzStemMatrixState GetStemMatrixState() const { return MatrixState; }

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Audio|Quartz")
	FOnFlowStateChanged OnFlowStateChanged;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Audio|Quartz")
	FOnQuartzBarDownbeat OnQuartzBarDownbeat;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Audio|Quartz")
	FOnAlchemicalFilterEngaged OnAlchemicalFilterEngaged;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Audio|Quartz")
	FOnStemMatrixUpdated OnStemMatrixUpdated;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Audio|Quartz")
	FQuartzStemMatrixState MatrixState;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Audio|Quartz")
	float FlowDurationRemainingSeconds = 0.0f;
};
