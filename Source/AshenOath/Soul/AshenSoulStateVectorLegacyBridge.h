// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenSoulStateVectorLegacyBridge.generated.h"

/**
 * UAshenSoulStateVectorLegacyBridge
 *
 * Bridge converting legacy 0-100 values to canonical 0.0-1.0 FSoulStateVector representation.
 */
UCLASS()
class ASHENOATH_API UAshenSoulStateVectorLegacyBridge : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** Converts legacy 0-100 raw float meters to normalized FSoulStateVector */
	UFUNCTION(BlueprintPure, Category = "AshenOath|LegacyBridge")
	static FSoulStateVector ConvertLegacyMetersToCanonicalVector(float RawSanity, float RawCorruption, float RawDebt);
};
