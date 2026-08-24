// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenUserWidget_ChaosNavmeshHUD.h"

UAshenUserWidget_ChaosNavmeshHUD::UAshenUserWidget_ChaosNavmeshHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	DisplayedSeverity = EChaosFractureSeverity::IntactSolid;
	DisplayedObstruction = ENavmeshObstructionState::ClearPath;
	DisplayedDebrisMass = 0.0f;
	DisplayedBlockingRadius = 150.0f;
	DisplayedAcousticFrequency = 450.0f;
}

void UAshenUserWidget_ChaosNavmeshHUD::UpdateChaosNavmeshHUD(
	EChaosFractureSeverity Severity,
	ENavmeshObstructionState Obstruction,
	float DebrisMassKg,
	float BlockingRadiusUU,
	float AcousticFreqHz)
{
	DisplayedSeverity = Severity;
	DisplayedObstruction = Obstruction;
	DisplayedDebrisMass = DebrisMassKg;
	DisplayedBlockingRadius = BlockingRadiusUU;
	DisplayedAcousticFrequency = AcousticFreqHz;
}
