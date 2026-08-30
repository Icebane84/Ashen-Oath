// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Soul/AshenSoulTypes.h"
#include "AshenSoulDerivationSubsystem.generated.h"

/**
 * UAshenSoulDerivationSubsystem
 * Evaluates continuous derived somatic signals from canonical FSoulStateVector using normalized mathematical manifolds (AOP-MASTER-CONVERGENCE-SPEC-V2.0).
 * Constitutional Law I & II: Zero persistent private meters; non-saturating derivations sum strictly to 1.00.
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenSoulDerivationSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	/** Internal Friction (Phi_internal): Resistance between intention and execution */
	UFUNCTION(BlueprintPure, Category = "Soul|Derivation")
	float CalculateInternalFriction(const FSoulStateVector& State, float LensShift = 0.0f, float ThreatLevel = 0.0f) const;

	/** Parasite Pressure (H): Eldrin's predatory momentum / Blade Hunger */
	UFUNCTION(BlueprintPure, Category = "Soul|Derivation")
	float CalculateParasitePressure(const FSoulStateVector& State, float InternalFriction) const;

	/** Relational Flow (Psi_relational): Moment-to-moment cooperative bandwidth */
	UFUNCTION(BlueprintPure, Category = "Soul|Derivation")
	float CalculateRelationalFlow(const FSoulStateVector& State, float ProximityFactor = 1.0f, float ThreatLevel = 0.0f, bool bSupportActive = false) const;

	/** Isolation Pressure (I): Psychological and spatial detachment */
	UFUNCTION(BlueprintPure, Category = "Soul|Derivation")
	float CalculateIsolationPressure(float RelationalFlow, float ProximityFactor) const;

	/** Full continuous somatic state derivation */
	UFUNCTION(BlueprintCallable, Category = "Soul|Derivation")
	FSomaticState EvaluateSomaticState(
		const FSoulStateVector& State,
		float LensShift = 0.0f,
		float ThreatLevel = 0.0f,
		float ProximityFactor = 1.0f,
		bool bSupportActive = false) const;
};
