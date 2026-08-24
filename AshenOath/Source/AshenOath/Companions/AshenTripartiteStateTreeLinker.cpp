// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Companions/AshenTripartiteStateTreeLinker.h"

UAshenTripartiteStateTreeLinker::UAshenTripartiteStateTreeLinker()
{
	PrimaryComponentTick.bCanEverTick = false;
}

bool UAshenTripartiteStateTreeLinker::ShouldPermitDialogueBarks(ETripartiteBehaviorMode Mode) const
{
	// Barks are permitted only during Combat or Campfire, STRICTLY FORBIDDEN during Contemplative or Trauma silence
	if (Mode == ETripartiteBehaviorMode::ContemplativeSilence || Mode == ETripartiteBehaviorMode::TraumaAftermath)
	{
		return false;
	}

	return true;
}
