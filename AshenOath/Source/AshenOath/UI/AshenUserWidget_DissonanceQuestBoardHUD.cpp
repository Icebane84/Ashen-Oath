// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenUserWidget_DissonanceQuestBoardHUD.h"

UAshenUserWidget_DissonanceQuestBoardHUD::UAshenUserWidget_DissonanceQuestBoardHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	DisplayedDissonance = 0.15f;
	DisplayedTier = ECognitiveDissonanceTier::HarmonicConsensus;
}

void UAshenUserWidget_DissonanceQuestBoardHUD::UpdateQuestBoardHUD(
	float DissonanceIndex,
	ECognitiveDissonanceTier Tier,
	const TArray<FDissonanceQuestContract>& Contracts)
{
	DisplayedDissonance = DissonanceIndex;
	DisplayedTier = Tier;
	DisplayedContracts = Contracts;
}
