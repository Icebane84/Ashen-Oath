// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Soul/AshenSoulStateVector.h"
#include "Orchestration/AshenMacroSystemicContractTypes.h"
#include "AshenSoulTypes.generated.h"

/**
 * FCompanionProfile_V2
 * Multi-dimensional companion psychological profile (TAM-001).
 */
USTRUCT(BlueprintType)
struct ASHENOATH_API FCompanionProfile_V2
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Soul|Relational")
	float InterpersonalTrust = 0.50f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Soul|Relational")
	float TacticalConfidence = 0.50f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Soul|Relational")
	float SomaticDread = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Soul|Relational")
	float TransferenceBurnout = 0.0f;
};

/**
 * FRelationalMatrix_V2
 * Multi-dimensional party relational matrix evaluating cooperative predicates.
 */
USTRUCT(BlueprintType)
struct ASHENOATH_API FRelationalMatrix_V2
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Soul|Relational")
	float TrioResonance = 0.50f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Soul|Relational")
	FCompanionProfile_V2 GarrettProfile;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Soul|Relational")
	FCompanionProfile_V2 SerafinaProfile;

	bool IsEligibleForRelationalFinisher() const
	{
		const bool bGarrettReady = (GarrettProfile.TacticalConfidence >= 0.60f) && (GarrettProfile.SomaticDread < 0.50f);
		const bool bSerafinaReady = (SerafinaProfile.TacticalConfidence >= 0.60f) && (SerafinaProfile.TransferenceBurnout < 0.80f);
		return (TrioResonance >= 0.70f) && bGarrettReady && bSerafinaReady;
	}
};
