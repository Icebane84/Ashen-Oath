// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Soul/AshenSoulDerivationSubsystem.h"

float UAshenSoulDerivationSubsystem::CalculateInternalFriction(
	const FSoulStateVector& State,
	float LensShift,
	float ThreatLevel) const
{
	// Formula: 0.25*D + 0.25*N_dysreg + 0.20*LensShift + 0.15*Threat + 0.15*(1.0 - R)
	// Normalized sum: 0.25 + 0.25 + 0.20 + 0.15 + 0.15 = 1.00
	const float Dysregulation = State.Isolation;
	const float Friction = (0.25f * State.IntegrationDebt) +
	                       (0.25f * Dysregulation) +
	                       (0.20f * FMath::Clamp(LensShift, 0.0f, 1.0f)) +
	                       (0.15f * FMath::Clamp(ThreatLevel, 0.0f, 1.0f)) +
	                       (0.15f * (1.0f - FMath::Clamp(State.Resolve, 0.0f, 1.0f)));

	return FMath::Clamp(Friction, 0.0f, 1.0f);
}

float UAshenSoulDerivationSubsystem::CalculateParasitePressure(
	const FSoulStateVector& State,
	float InternalFriction) const
{
	// Formula: 0.40*C + 0.35*Phi_internal + 0.25*(1.0 - R)
	// Normalized sum: 0.40 + 0.35 + 0.25 = 1.00
	const float Hunger = (0.40f * State.Corruption) +
	                     (0.35f * FMath::Clamp(InternalFriction, 0.0f, 1.0f)) +
	                     (0.25f * (1.0f - FMath::Clamp(State.Resolve, 0.0f, 1.0f)));

	return FMath::Clamp(Hunger, 0.0f, 1.0f);
}

float UAshenSoulDerivationSubsystem::CalculateRelationalFlow(
	const FSoulStateVector& State,
	float ProximityFactor,
	float ThreatLevel,
	bool bSupportActive) const
{
	// Formula: 0.45*TrioResonance + 0.25*ProximityFactor + 0.20*(1.0 - Threat) + 0.10*bSupportActive
	// Normalized sum: 0.45 + 0.25 + 0.20 + 0.10 = 1.00
	const float TrioResonance = (State.GarrettTrust + State.SerafinaTrust) * 0.5f;
	const float SupportWeight = bSupportActive ? 1.0f : 0.0f;
	const float Flow = (0.45f * TrioResonance) +
	                   (0.25f * FMath::Clamp(ProximityFactor, 0.0f, 1.0f)) +
	                   (0.20f * (1.0f - FMath::Clamp(ThreatLevel, 0.0f, 1.0f))) +
	                   (0.10f * SupportWeight);

	return FMath::Clamp(Flow, 0.0f, 1.0f);
}

float UAshenSoulDerivationSubsystem::CalculateIsolationPressure(
	float RelationalFlow,
	float ProximityFactor) const
{
	// Formula: 0.55*(1.0 - Psi_relational) + 0.45*(1.0 - ProximityFactor)
	// Normalized sum: 0.55 + 0.45 = 1.00
	const float Isolation = (0.55f * (1.0f - FMath::Clamp(RelationalFlow, 0.0f, 1.0f))) +
	                        (0.45f * (1.0f - FMath::Clamp(ProximityFactor, 0.0f, 1.0f)));

	return FMath::Clamp(Isolation, 0.0f, 1.0f);
}

FSomaticState UAshenSoulDerivationSubsystem::EvaluateSomaticState(
	const FSoulStateVector& State,
	float LensShift,
	float ThreatLevel,
	float ProximityFactor,
	bool bSupportActive) const
{
	FSomaticState Somatic;
	Somatic.InternalFriction = CalculateInternalFriction(State, LensShift, ThreatLevel);
	Somatic.ParasitePressure = CalculateParasitePressure(State, Somatic.InternalFriction);
	Somatic.RelationalFlow   = CalculateRelationalFlow(State, ProximityFactor, ThreatLevel, bSupportActive);
	Somatic.IsolationPressure = CalculateIsolationPressure(Somatic.RelationalFlow, ProximityFactor);
	Somatic.WillCapacity     = FMath::Clamp(State.Resolve * (1.0f - Somatic.InternalFriction), 0.0f, 1.0f);

	return Somatic;
}
