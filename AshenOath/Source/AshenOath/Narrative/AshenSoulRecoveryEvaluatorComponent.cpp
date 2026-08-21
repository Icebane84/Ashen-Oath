// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenSoulRecoveryEvaluatorComponent.h"

UAshenSoulRecoveryEvaluatorComponent::UAshenSoulRecoveryEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FCampfireIntegrationSnapshot UAshenSoulRecoveryEvaluatorComponent::EvaluateRestSession(
	float IntegrationDebt,
	float Dysregulation) const
{
	FCampfireIntegrationSnapshot Snapshot;
	Snapshot.SessionId = FGuid::NewGuid().ToString(EGuidFormats::DigitsWithHyphensLower);
	Snapshot.InitialIntegrationDebt = IntegrationDebt;
	Snapshot.InitialDysregulation = Dysregulation;

	if (IntegrationDebt >= 0.70f || Dysregulation >= 0.70f)
	{
		Snapshot.RestTier = ECampfireRestTier::SolemnVigil;
		Snapshot.TransmutedTraitBonus = 0.15f;
		Snapshot.bCatharsisDialogueTriggered = true;
	}
	else if (IntegrationDebt >= 0.30f)
	{
		Snapshot.RestTier = ECampfireRestTier::ReflectiveTransmute;
		Snapshot.TransmutedTraitBonus = 0.10f;
		Snapshot.bCatharsisDialogueTriggered = false;
	}
	else
	{
		Snapshot.RestTier = ECampfireRestTier::MinorRest;
		Snapshot.TransmutedTraitBonus = 0.05f;
		Snapshot.bCatharsisDialogueTriggered = false;
	}

	return Snapshot;
}
