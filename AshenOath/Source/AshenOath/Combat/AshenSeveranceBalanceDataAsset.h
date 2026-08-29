// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Combat/AshenSeveranceTypes.h"
#include "AshenSeveranceBalanceDataAsset.generated.h"

USTRUCT(BlueprintType)
struct FSeveranceImpulseBalancing
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Impulse Balancing", meta = (ClampMin = "200.0", ClampMax = "2500.0"))
	float DecapitationImpulse = 750.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Impulse Balancing", meta = (ClampMin = "300.0", ClampMax = "3000.0"))
	float TorsoBisectionImpulse = 1100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Impulse Balancing", meta = (ClampMin = "200.0", ClampMax = "2000.0"))
	float LimbAmputationImpulse = 650.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Impulse Balancing", meta = (ClampMin = "200.0", ClampMax = "2000.0"))
	float LegCrippleImpulse = 700.0f;
};

USTRUCT(BlueprintType)
struct FAdrenalineSurgeBalancing
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adrenaline Balancing", meta = (ClampMin = "10.0", ClampMax = "100.0"))
	float DecapitationAdrenaline = 35.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adrenaline Balancing", meta = (ClampMin = "10.0", ClampMax = "100.0"))
	float BisectionAdrenaline = 40.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adrenaline Balancing", meta = (ClampMin = "5.0", ClampMax = "60.0"))
	float MajorLimbAdrenaline = 25.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adrenaline Balancing", meta = (ClampMin = "0.1", ClampMax = "1.0"))
	float StaminaRefillScalar = 0.50f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adrenaline Balancing", meta = (ClampMin = "20.0", ClampMax = "100.0"))
	float HyperArmorThreshold = 50.0f;
};

/**
 * UAshenSeveranceBalanceDataAsset
 * Primary DataAsset exposing live editor tuning parameters for Executioner's Severance & Dismemberment Physics (SEVERANCE-DISMEMBERMENT-SPEC-099).
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenSeveranceBalanceDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Convergence | Severance Impulses")
	FSeveranceImpulseBalancing ImpulseBalancing;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Convergence | Adrenaline Surge")
	FAdrenalineSurgeBalancing AdrenalineBalancing;

	FSeveranceImpulseBalancing GetClampedImpulses() const;
	FAdrenalineSurgeBalancing GetClampedAdrenaline() const;
};
