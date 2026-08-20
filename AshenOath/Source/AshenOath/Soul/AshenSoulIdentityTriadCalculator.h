// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenSoulIdentityTriadCalculator.generated.h"

/**
 * UAshenSoulIdentityTriadCalculator
 *
 * Blueprint Function Library for identity triad calculation and normalization.
 */
UCLASS()
class ASHENOATH_API UAshenSoulIdentityTriadCalculator : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** Calculates normalized identity stability metric (0.0 - 1.0) */
	UFUNCTION(BlueprintPure, Category = "AshenOath|Soul")
	static float CalculateIdentityStability(const FSoulStateVector& SoulState);

	/** Clamps and normalizes a soul state vector */
	UFUNCTION(BlueprintPure, Category = "AshenOath|Soul")
	static FSoulStateVector NormalizeSoulStateVector(const FSoulStateVector& RawState);
};
