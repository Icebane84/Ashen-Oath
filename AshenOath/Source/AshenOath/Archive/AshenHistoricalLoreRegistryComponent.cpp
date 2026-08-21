// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Archive/AshenHistoricalLoreRegistryComponent.h"

UAshenHistoricalLoreRegistryComponent::UAshenHistoricalLoreRegistryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FText UAshenHistoricalLoreRegistryComponent::GetDefaultLoreTemplate(ECodexCategory Category) const
{
	switch (Category)
	{
	case ECodexCategory::BossAnatomy:
		return FText::FromString(TEXT("Titan Physiology: Formed from crystallized Nightsteel veins and ancient marrow."));
	case ECodexCategory::AncientRelics:
		return FText::FromString(TEXT("Sacred Artifact: Inscribed with pre-Fall runes humming with harmonic Solfeggio resonance."));
	case ECodexCategory::FactionHistory:
		return FText::FromString(TEXT("Order of the Pyre: Zealous paladins who sought purification through immolation."));
	case ECodexCategory::CompanionMemories:
		return FText::FromString(TEXT("Companion Chronicle: Fragmented memories preserved across campfire hearth vigils."));
	case ECodexCategory::WorldGeography:
	default:
		return FText::FromString(TEXT("The Ashlands: A fractured realm beneath eternal cinder storms."));
	}
}
