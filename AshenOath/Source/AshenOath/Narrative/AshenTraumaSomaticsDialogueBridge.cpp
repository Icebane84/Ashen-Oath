// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenTraumaSomaticsDialogueBridge.h"

UAshenTraumaSomaticsDialogueBridge::UAshenTraumaSomaticsDialogueBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FText UAshenTraumaSomaticsDialogueBridge::FormatSomaticObservationBark(ETraumaSomaticStage Stage) const
{
	switch (Stage)
	{
	case ETraumaSomaticStage::Stage0_BaselinePristine:
		return FText::FromString(TEXT("[Garrett]: 'You look steady, Kaelen. Keep your focus.'"));
	case ETraumaSomaticStage::Stage1_SubcutaneousTaint:
		return FText::FromString(TEXT("[Serafina]: 'Kaelen... the veins along your neck are darkening. Breathe.'"));
	case ETraumaSomaticStage::Stage2_VascularCrisis:
		return FText::FromString(TEXT("[Garrett]: 'Your hands are shaking, Kaelen! Step back before your grip gives out!'"));
	case ETraumaSomaticStage::Stage3_ShatteredVessel:
	default:
		return FText::FromString(TEXT("[Serafina]: 'Black blood at his temple—Garrett, he's slipping into the Oakhaven void!'"));
	}
}
