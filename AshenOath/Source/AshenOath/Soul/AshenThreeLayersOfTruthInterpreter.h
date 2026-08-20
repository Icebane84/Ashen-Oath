// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenThreeLayersOfTruthInterpreter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnThreeLayersEvaluatedSignature, FName, LayerIRalitySummary, FName, LayerIIInterpretationSummary, FName, LayerIIISomaticSummary);

/**
 * UAshenThreeLayersOfTruthInterpreter
 *
 * Subsystem coordinating Layer I (Reality), Layer II (Interpretation), and Layer III (Somatic Presentation).
 */
UCLASS()
class ASHENOATH_API UAshenThreeLayersOfTruthInterpreter : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|TruthLayers")
	void EvaluateThreeLayersOfTruth(float IntegrationDebt, float Resolve, float Isolation);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|TruthLayers|Events")
	FOnThreeLayersEvaluatedSignature OnLayersEvaluated;
};
