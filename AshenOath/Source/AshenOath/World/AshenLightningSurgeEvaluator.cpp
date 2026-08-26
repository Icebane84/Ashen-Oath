// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AshenLightningSurgeEvaluator.h"

UAshenLightningSurgeEvaluator::UAshenLightningSurgeEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenLightningSurgeEvaluator::EvaluateLightningStrikeDamage(EAtmosphericSeverity Severity) const
{
	switch (Severity)
	{
	case EAtmosphericSeverity::SevereCataclysm:
		return 1250.0f;
	case EAtmosphericSeverity::ModerateGale:
		return 850.0f;
	case EAtmosphericSeverity::MildDrift:
	default:
		return 550.0f;
	}
}
