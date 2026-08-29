// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenSyncFinisherBalanceDataAsset.h"

FSyncedShadowStrikeBalancing UAshenSyncFinisherBalanceDataAsset::GetClampedShadowStrike() const
{
	FSyncedShadowStrikeBalancing Clamped = ShadowStrikeParams;
	Clamped.BaseDamage = FMath::Clamp(Clamped.BaseDamage, 100.0f, 2000.0f);
	Clamped.StaggeredMultiplier = FMath::Clamp(Clamped.StaggeredMultiplier, 1.0f, 3.5f);
	Clamped.GarrettFatigueCost = FMath::Clamp(Clamped.GarrettFatigueCost, 0.05f, 0.60f);
	Clamped.Radius = FMath::Clamp(Clamped.Radius, 200.0f, 1200.0f);
	return Clamped;
}

FSyncedHolyBurstBalancing UAshenSyncFinisherBalanceDataAsset::GetClampedHolyBurst() const
{
	FSyncedHolyBurstBalancing Clamped = HolyBurstParams;
	Clamped.BaseDamage = FMath::Clamp(Clamped.BaseDamage, 100.0f, 1500.0f);
	Clamped.SanityAndHealthHeal = FMath::Clamp(Clamped.SanityAndHealthHeal, 10.0f, 200.0f);
	Clamped.SerafinaFatigueCost = FMath::Clamp(Clamped.SerafinaFatigueCost, 0.05f, 0.60f);
	Clamped.Radius = FMath::Clamp(Clamped.Radius, 300.0f, 1500.0f);
	return Clamped;
}

FTripartiteZenithBalancing UAshenSyncFinisherBalanceDataAsset::GetClampedTripartiteZenith() const
{
	FTripartiteZenithBalancing Clamped = TripartiteZenithParams;
	Clamped.BaseDamage = FMath::Clamp(Clamped.BaseDamage, 500.0f, 10000.0f);
	Clamped.PoiseDamage = FMath::Clamp(Clamped.PoiseDamage, 100.0f, 1500.0f);
	Clamped.TimeDilationScale = FMath::Clamp(Clamped.TimeDilationScale, 0.05f, 0.50f);
	Clamped.CompanionFatigueCost = FMath::Clamp(Clamped.CompanionFatigueCost, 0.10f, 0.60f);
	Clamped.Radius = FMath::Clamp(Clamped.Radius, 500.0f, 2500.0f);
	return Clamped;
}
