// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenUserWidget_TraumaSomaticsHUD.h"

UAshenUserWidget_TraumaSomaticsHUD::UAshenUserWidget_TraumaSomaticsHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	DisplayedStage = ETraumaSomaticStage::Stage0_BaselinePristine;
	DisplayedVeinCorruption = 0.0f;
	DisplayedBPM = 60.0f;
	DisplayedBladeSoot = 0.0f;
	DisplayedNicks = 0;
}

void UAshenUserWidget_TraumaSomaticsHUD::UpdateSomaticsDisplay(
	ETraumaSomaticStage Stage,
	float VeinCorruption,
	float HeartBPM,
	float BladeSoot,
	int32 MicroNicks)
{
	DisplayedStage = Stage;
	DisplayedVeinCorruption = VeinCorruption;
	DisplayedBPM = HeartBPM;
	DisplayedBladeSoot = BladeSoot;
	DisplayedNicks = MicroNicks;
}
