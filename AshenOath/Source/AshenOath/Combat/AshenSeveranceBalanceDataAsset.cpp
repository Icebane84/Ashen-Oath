// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenSeveranceBalanceDataAsset.h"

FSeveranceImpulseBalancing UAshenSeveranceBalanceDataAsset::GetClampedImpulses() const
{
	FSeveranceImpulseBalancing Clamped = ImpulseBalancing;
	Clamped.DecapitationImpulse = FMath::Clamp(Clamped.DecapitationImpulse, 200.0f, 2500.0f);
	Clamped.TorsoBisectionImpulse = FMath::Clamp(Clamped.TorsoBisectionImpulse, 300.0f, 3000.0f);
	Clamped.LimbAmputationImpulse = FMath::Clamp(Clamped.LimbAmputationImpulse, 200.0f, 2000.0f);
	Clamped.LegCrippleImpulse = FMath::Clamp(Clamped.LegCrippleImpulse, 200.0f, 2000.0f);
	return Clamped;
}

FAdrenalineSurgeBalancing UAshenSeveranceBalanceDataAsset::GetClampedAdrenaline() const
{
	FAdrenalineSurgeBalancing Clamped = AdrenalineBalancing;
	Clamped.DecapitationAdrenaline = FMath::Clamp(Clamped.DecapitationAdrenaline, 10.0f, 100.0f);
	Clamped.BisectionAdrenaline = FMath::Clamp(Clamped.BisectionAdrenaline, 10.0f, 100.0f);
	Clamped.MajorLimbAdrenaline = FMath::Clamp(Clamped.MajorLimbAdrenaline, 5.0f, 60.0f);
	Clamped.StaminaRefillScalar = FMath::Clamp(Clamped.StaminaRefillScalar, 0.10f, 1.0f);
	Clamped.HyperArmorThreshold = FMath::Clamp(Clamped.HyperArmorThreshold, 20.0f, 100.0f);
	return Clamped;
}
