// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenUserWidget_RunicForgeHUD.h"

UAshenUserWidget_RunicForgeHUD::UAshenUserWidget_RunicForgeHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	DisplayedTier = EOathbringerAscensionTier::Tier1_DullNightsteel;
	DisplayedVomTag = ESigilResonanceEffect::None;
	DisplayedPflug = ESigilResonanceEffect::None;
	DisplayedOchs = ESigilResonanceEffect::None;
	DisplayedMordhau = ESigilResonanceEffect::None;
}

void UAshenUserWidget_RunicForgeHUD::UpdateForgeHUD(
	EOathbringerAscensionTier Tier,
	ESigilResonanceEffect VomTagSigil,
	ESigilResonanceEffect PflugSigil,
	ESigilResonanceEffect OchsSigil,
	ESigilResonanceEffect MordhauSigil)
{
	DisplayedTier = Tier;
	DisplayedVomTag = VomTagSigil;
	DisplayedPflug = PflugSigil;
	DisplayedOchs = OchsSigil;
	DisplayedMordhau = MordhauSigil;
}
