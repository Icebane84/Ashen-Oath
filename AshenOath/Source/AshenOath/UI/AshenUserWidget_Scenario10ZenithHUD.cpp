// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenUserWidget_Scenario10ZenithHUD.h"

UAshenUserWidget_Scenario10ZenithHUD::UAshenUserWidget_Scenario10ZenithHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	DisplayedResonance = 0.0f;
	DisplayedTrust = 0.85f;
	DisplayedDebt = 0.20f;
	DisplayedDamageMultiplier = 1.0f;
	DisplayedStage = EApotheosisResonanceStage::DormantLatent;
	DisplayedEnding = EZenithConsequenceEnding::RadiantTransfiguration;
}

void UAshenUserWidget_Scenario10ZenithHUD::UpdateZenithHUD(
	float Resonance01,
	float TrustScore01,
	float Debt01,
	float DamageMultiplier,
	EApotheosisResonanceStage Stage,
	EZenithConsequenceEnding Ending)
{
	DisplayedResonance = Resonance01;
	DisplayedTrust = TrustScore01;
	DisplayedDebt = Debt01;
	DisplayedDamageMultiplier = DamageMultiplier;
	DisplayedStage = Stage;
	DisplayedEnding = Ending;
}
