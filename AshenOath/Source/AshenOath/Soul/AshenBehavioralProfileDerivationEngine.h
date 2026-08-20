// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenBehavioralProfileDerivationEngine.generated.h"

/**
 * UAshenBehavioralProfileDerivationEngine
 *
 * Blueprint Function Library that deterministically derives discrete behavioral profiles
 * (Stance, Empathic, Tactical) from Kaelen's canonical FSoulStateVector.
 */
UCLASS()
class ASHENOATH_API UAshenBehavioralProfileDerivationEngine : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** Derives FBehavioralProfile struct from raw FSoulStateVector */
	UFUNCTION(BlueprintPure, Category = "AshenOath|Soul")
	static FBehavioralProfile DeriveBehavioralProfile(const FSoulStateVector& SoulState);

	/** Evaluates StanceProfile derived from Resolve and Corruption */
	UFUNCTION(BlueprintPure, Category = "AshenOath|Soul")
	static EStanceProfile EvaluateStanceProfile(float Resolve, float Corruption);

	/** Evaluates EmpathicProfile derived from SerafinaTrust and Isolation */
	UFUNCTION(BlueprintPure, Category = "AshenOath|Soul")
	static EEmpathicProfile EvaluateEmpathicProfile(float SerafinaTrust, float Isolation);

	/** Evaluates ETacticalProfile derived from GarrettTrust and Isolation */
	UFUNCTION(BlueprintPure, Category = "AshenOath|Soul")
	static ETacticalProfile EvaluateTacticalProfile(float GarrettTrust, float Isolation);
};
