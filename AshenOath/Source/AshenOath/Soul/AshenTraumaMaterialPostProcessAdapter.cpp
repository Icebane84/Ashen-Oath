// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Soul/AshenTraumaMaterialPostProcessAdapter.h"

UAshenTraumaMaterialPostProcessAdapter::UAshenTraumaMaterialPostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenTraumaMaterialPostProcessAdapter::EvaluateChromaticAberrationIntensity(ETraumaSomaticStage Stage) const
{
	switch (Stage)
	{
	case ETraumaSomaticStage::Stage0_BaselinePristine:
		return 0.0f;
	case ETraumaSomaticStage::Stage1_SubcutaneousTaint:
		return 0.8f;
	case ETraumaSomaticStage::Stage2_VascularCrisis:
		return 2.4f;
	case ETraumaSomaticStage::Stage3_ShatteredVessel:
	default:
		return 5.0f;
	}
}
