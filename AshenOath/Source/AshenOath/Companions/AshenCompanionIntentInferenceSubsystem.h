// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Companions/AshenCompanionIntentTypes.h"
#include "AshenCompanionIntentInferenceSubsystem.generated.h"

class UAshenGarrettIntentEvaluatorComponent;
class UAshenSerafinaEmpathicIntentEvaluatorComponent;
class UAshenHistoricalIntentProvenanceAuditor;

/**
 * UAshenCompanionIntentInferenceSubsystem
 * 
 * Central subsystem evaluating Kaelen's kinetic movements and formation breaks
 * to broadcast inferred intent to companion AI evaluators.
 */
UCLASS()
class ASHENOATH_API UAshenCompanionIntentInferenceSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenCompanionIntentInferenceSubsystem();

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	/** Ingests player formation break telemetry */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Companions|Intent")
	FCompanionIntentEvaluationResult EvaluatePlayerFormationBreak(
		FName CompanionId,
		const FPlayerIntentTelemetrySnapshot& TelemetrySnapshot);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Companions|Intent")
	FOnPlayerFormationBreakDetected OnPlayerFormationBreakDetected;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Companions|Intent")
	FOnCompanionIntentEvaluated OnCompanionIntentEvaluated;

protected:
	UPROPERTY()
	UAshenGarrettIntentEvaluatorComponent* GarrettEvaluator;

	UPROPERTY()
	UAshenSerafinaEmpathicIntentEvaluatorComponent* SerafinaEvaluator;

	UPROPERTY()
	UAshenHistoricalIntentProvenanceAuditor* ProvenanceAuditor;
};
