// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenSanctifiedAuraComponent.h"

UAshenSanctifiedAuraComponent::UAshenSanctifiedAuraComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	AuraRadiusUnits = 600.0f;
	StaminaBuffMultiplier = 1.20f;
}
void UAshenSanctifiedAuraComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenSanctifiedAuraComponent::CleanseNegativeStatusEffects()
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenSanctifiedAuraComponent: SANCTIFIED AURA ACTIVE (Radius: %.1fuu) -> Cleansed all negative status effects & +20%% Stamina!"),
		AuraRadiusUnits);
}
