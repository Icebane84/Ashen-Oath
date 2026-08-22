// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenKineticBerserkDialogueBridge.h"

UAshenKineticBerserkDialogueBridge::UAshenKineticBerserkDialogueBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FText UAshenKineticBerserkDialogueBridge::FormatRiposteBark(EAshenCounterAttackZone CounterZone) const
{
	switch (CounterZone)
	{
	case EAshenCounterAttackZone::VerticalOverhead:
		return FText::FromString(TEXT("[Garrett]: 'Clean overhead redirect! Split them in two!'"));
	case EAshenCounterAttackZone::HorizontalLeft:
	case EAshenCounterAttackZone::HorizontalRight:
		return FText::FromString(TEXT("[Garrett]: 'Turned their blade aside—follow the seam!'"));
	case EAshenCounterAttackZone::DiagonalUnderhand:
	default:
		return FText::FromString(TEXT("[Garrett]: 'Underhand lift! Catch them off-balance!'"));
	}
}
