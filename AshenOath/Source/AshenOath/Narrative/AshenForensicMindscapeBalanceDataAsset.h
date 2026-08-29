// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Narrative/AshenForensicMindscapeTypes.h"
#include "AshenForensicMindscapeBalanceDataAsset.generated.h"

USTRUCT(BlueprintType)
struct FForensicDeductionBalancing
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Deduction Balancing", meta = (ClampMin = "0.50", ClampMax = "1.00"))
	float ResolutionSynthesisThreshold = 0.85f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Deduction Balancing", meta = (ClampMin = "0.10", ClampMax = "0.80"))
	float ClueBaseWeightMultiplier = 0.35f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Deduction Balancing", meta = (ClampMin = "10.0", ClampMax = "100.0"))
	float SolvedCaseSanityCatharsis = 50.0f;
};

USTRUCT(BlueprintType)
struct FEvidenceReliabilityBalancing
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Reliability Balancing", meta = (ClampMin = "0.50", ClampMax = "1.00"))
	float AutopsyReliabilityWeight = 1.00f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Reliability Balancing", meta = (ClampMin = "0.50", ClampMax = "1.00"))
	float ChemicalReliabilityWeight = 0.95f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Reliability Balancing", meta = (ClampMin = "0.40", ClampMax = "1.00"))
	float RunicReliabilityWeight = 0.85f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Reliability Balancing", meta = (ClampMin = "0.20", ClampMax = "1.00"))
	float TestimonyReliabilityWeight = 0.65f;
};

/**
 * UAshenForensicMindscapeBalanceDataAsset
 * Primary DataAsset exposing live editor tuning parameters for Forensic Deduction & Memory Palace Synthesis (FORENSIC-MINDSCAPE-SPEC-097).
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenForensicMindscapeBalanceDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Convergence | Deduction")
	FForensicDeductionBalancing DeductionBalancing;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Convergence | Reliability")
	FEvidenceReliabilityBalancing ReliabilityBalancing;

	FForensicDeductionBalancing GetClampedDeduction() const;
	FEvidenceReliabilityBalancing GetClampedReliability() const;
};
