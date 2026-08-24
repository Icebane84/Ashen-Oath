// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Companions/AshenCompanionSilenceTransitionHandler.h"

UAshenCompanionSilenceTransitionHandler::UAshenCompanionSilenceTransitionHandler()
{
	PrimaryComponentTick.bCanEverTick = false;
}

ETripartiteBehaviorMode UAshenCompanionSilenceTransitionHandler::ResolvePostCombatSilenceMode(
	float IntegrationDebt,
	bool bAnyCompanionDowned) const
{
	// If trauma/debt is high (>0.60) or a companion was downed, enter Trauma Aftermath (alienated distance)
	if (IntegrationDebt > 0.60f || bAnyCompanionDowned)
	{
		return ETripartiteBehaviorMode::TraumaAftermath;
	}

	// Otherwise, enter peaceful Contemplative Silence (matching stride)
	return ETripartiteBehaviorMode::ContemplativeSilence;
}
