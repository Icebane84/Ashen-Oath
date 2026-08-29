// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AshenConductiveLightningArcEvaluator.h"

UAshenConductiveLightningArcEvaluator::UAshenConductiveLightningArcEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

bool UAshenConductiveLightningArcEvaluator::IsSurfaceConductive(
	EConductiveSurfaceType SurfaceType) const
{
	return SurfaceType != EConductiveSurfaceType::NonConductiveStone;
}

float UAshenConductiveLightningArcEvaluator::EvaluateChainShockDamage(
	EConductiveSurfaceType SurfaceType) const
{
	switch (SurfaceType)
	{
	case EConductiveSurfaceType::WetAcidPuddle:
		return 350.0f;
	case EConductiveSurfaceType::MetallicIronRubble:
		return 400.0f;
	case EConductiveSurfaceType::HeavyMetalArmor:
		return 450.0f;
	case EConductiveSurfaceType::NonConductiveStone:
	default:
		return 0.0f;
	}
}

float UAshenConductiveLightningArcEvaluator::EvaluateParalysisStaggerSeconds(
	EConductiveSurfaceType SurfaceType) const
{
	if (IsSurfaceConductive(SurfaceType))
	{
		return 1.20f;
	}
	return 0.0f;
}
