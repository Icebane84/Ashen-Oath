// Copyright Ashen Oath Tactical RPG. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenForensicMindscapeTypes.h"
#include "Narrative/AshenForensicMindscapeBalanceDataAsset.h"
#include "AshenMemoryPalaceSynthesisEvaluator.generated.h"

/**
 * UAshenMemoryPalaceSynthesisEvaluator
 * 
 * Computes evidence synthesis coherence (S >= 0.85 indicates case solved)
 * and identifies testimonial contradictions with DataAsset support.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMemoryPalaceSynthesisEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenMemoryPalaceSynthesisEvaluator();

	/** Evaluates synthesis score based on pinned clue count and reliability weights */
	UFUNCTION(BlueprintPure, Category = "Ashen|Forensic|Evaluator")
	float EvaluateSynthesisScore(int32 PinnedCluesCount, float AverageReliability) const;

	/** Evaluates whether synthesis threshold is reached [>=0.85] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Forensic|Evaluator")
	bool IsCaseResolvable(float SynthesisScore) const;

	/** Detects contradiction between physical evidence and companion dogma */
	UFUNCTION(BlueprintPure, Category = "Ashen|Forensic|Evaluator")
	bool DetectContradiction(EForensicClueCategory ClueA, EForensicClueCategory ClueB) const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Forensic|Balancing")
	UAshenForensicMindscapeBalanceDataAsset* BalanceDataAsset;
};
