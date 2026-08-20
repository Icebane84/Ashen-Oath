// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Soul/AshenBehavioralProfileDerivationEngine.h"

FBehavioralProfile UAshenBehavioralProfileDerivationEngine::DeriveBehavioralProfile(const FSoulStateVector& SoulState)
{
	FBehavioralProfile Profile;
	Profile.Stance = EvaluateStanceProfile(SoulState.Resolve, SoulState.Corruption);
	Profile.Empathic = EvaluateEmpathicProfile(SoulState.SerafinaTrust, SoulState.Isolation);
	Profile.Tactical = EvaluateTacticalProfile(SoulState.GarrettTrust, SoulState.Isolation);
	return Profile;
}

EStanceProfile UAshenBehavioralProfileDerivationEngine::EvaluateStanceProfile(float Resolve, float Corruption)
{
	if (Resolve < 0.35f || Corruption > 0.65f)
	{
		return EStanceProfile::Hunched_Guarded;
	}
	else if (Resolve > 0.70f && Corruption < 0.30f)
	{
		return EStanceProfile::Upright_Grounded;
	}
	return EStanceProfile::Balanced_Steady;
}

EEmpathicProfile UAshenBehavioralProfileDerivationEngine::EvaluateEmpathicProfile(float SerafinaTrust, float Isolation)
{
	if (SerafinaTrust < 0.30f || Isolation > 0.70f)
	{
		return EEmpathicProfile::Burned_Out;
	}
	else if (SerafinaTrust > 0.75f)
	{
		return EEmpathicProfile::Radiant_Shield;
	}
	return EEmpathicProfile::Resonant_Attuned;
}

ETacticalProfile UAshenBehavioralProfileDerivationEngine::EvaluateTacticalProfile(float GarrettTrust, float Isolation)
{
	if (GarrettTrust < 0.35f || Isolation > 0.65f)
	{
		return ETacticalProfile::Cynical_Isolated;
	}
	else if (GarrettTrust > 0.70f)
	{
		return ETacticalProfile::Unshakeable_Anchor;
	}
	return ETacticalProfile::Calculated_Pragmatic;
}
