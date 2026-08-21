// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenUserWidget_SentinelsGambitHUD.h"

UAshenUserWidget_SentinelsGambitHUD::UAshenUserWidget_SentinelsGambitHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	DisplayedTrapsPlaced = 0;
	DisplayedAIUtility = 1.0f;
	DisplayedFunneledCount = 0;
}

void UAshenUserWidget_SentinelsGambitHUD::UpdateTacticalDiagnostics(
	int32 TrapsPlaced,
	float AIUtilityScore,
	int32 FunneledCount)
{
	DisplayedTrapsPlaced = TrapsPlaced;
	DisplayedAIUtility = AIUtilityScore;
	DisplayedFunneledCount = FunneledCount;
}
