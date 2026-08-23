// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenWaystationDialogueBridge.h"

UAshenWaystationDialogueBridge::UAshenWaystationDialogueBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FText UAshenWaystationDialogueBridge::FormatRunBark(EWaystationRunMode Mode) const
{
	switch (Mode)
	{
	case EWaystationRunMode::RunA_ShadowHarvest:
		return FText::FromString(TEXT("[Garrett]: 'Cold, but efficient. We needed that edge.'"));
	case EWaystationRunMode::RunB_PureGrace:
		return FText::FromString(TEXT("[Garrett]: 'Noble. Hope that kindness doesn't get us ambushed down the road.'"));
	case EWaystationRunMode::RunC_TheSpiral:
		return FText::FromString(TEXT("[Garrett]: 'God damn it, Kaelen! He was pinned! He wasn't a threat!'"));
	case EWaystationRunMode::RunD_AvoidantMercy:
	default:
		return FText::FromString(TEXT("[Garrett]: 'You couldn't even look him in the eye, Kaelen. That wasn't mercy—it was dissociation.'"));
	}
}
