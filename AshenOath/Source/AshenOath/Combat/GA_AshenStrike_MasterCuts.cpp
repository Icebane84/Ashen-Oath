// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/GA_AshenStrike_MasterCuts.h"

UGA_AshenStrike_Zornhau::UGA_AshenStrike_Zornhau()
{
	StrikeParams.StrikeType = EAshenMasterCutType::Zornhau;
	StrikeParams.BaseDamage = 85.0f;
	StrikeParams.PoiseDamage = 50.0f;
	StrikeParams.ArmorPenetrationFraction = 0.25f;
	StrikeParams.StaminaCost = 28.0f;
	StrikeParams.RequiredGuardTag = FGameplayTag::RequestGameplayTag(FName("State.Stance.VomTag"));
	StrikeParams.NextGuardTag = FGameplayTag::RequestGameplayTag(FName("State.Stance.Pflug"));
	StrikeParams.ApexTimeSeconds = 0.55f;
	StrikeParams.WindowDurationSeconds = 0.15f;
}

UGA_AshenStrike_Krumphau::UGA_AshenStrike_Krumphau()
{
	StrikeParams.StrikeType = EAshenMasterCutType::Krumphau;
	StrikeParams.BaseDamage = 60.0f;
	StrikeParams.PoiseDamage = 75.0f; // High Poise/Shield Breaker
	StrikeParams.ArmorPenetrationFraction = 0.35f;
	StrikeParams.StaminaCost = 22.0f;
	StrikeParams.RequiredGuardTag = FGameplayTag::RequestGameplayTag(FName("State.Stance.Ochs"));
	StrikeParams.NextGuardTag = FGameplayTag::RequestGameplayTag(FName("State.Stance.VomTag"));
	StrikeParams.ApexTimeSeconds = 0.45f;
	StrikeParams.WindowDurationSeconds = 0.15f;
}

UGA_AshenStrike_Zwerchhau::UGA_AshenStrike_Zwerchhau()
{
	StrikeParams.StrikeType = EAshenMasterCutType::Zwerchhau;
	StrikeParams.BaseDamage = 65.0f;
	StrikeParams.PoiseDamage = 35.0f;
	StrikeParams.ArmorPenetrationFraction = 0.30f;
	StrikeParams.StaminaCost = 20.0f;
	StrikeParams.RequiredGuardTag = FGameplayTag::RequestGameplayTag(FName("State.Stance.Ochs"));
	StrikeParams.NextGuardTag = FGameplayTag::RequestGameplayTag(FName("State.Stance.Ochs")); // Chains to itself
	StrikeParams.ApexTimeSeconds = 0.40f;
	StrikeParams.WindowDurationSeconds = 0.15f;
}

UGA_AshenStrike_Schielhau::UGA_AshenStrike_Schielhau()
{
	StrikeParams.StrikeType = EAshenMasterCutType::Schielhau;
	StrikeParams.BaseDamage = 70.0f;
	StrikeParams.PoiseDamage = 40.0f;
	StrikeParams.ArmorPenetrationFraction = 0.50f; // 50% Armor Penetration
	StrikeParams.StaminaCost = 24.0f;
	StrikeParams.RequiredGuardTag = FGameplayTag::RequestGameplayTag(FName("State.Stance.Pflug"));
	StrikeParams.NextGuardTag = FGameplayTag::RequestGameplayTag(FName("State.Stance.Ochs"));
	StrikeParams.ApexTimeSeconds = 0.50f;
	StrikeParams.WindowDurationSeconds = 0.15f;
}

UGA_AshenStrike_Scheitelhau::UGA_AshenStrike_Scheitelhau()
{
	StrikeParams.StrikeType = EAshenMasterCutType::Scheitelhau;
	StrikeParams.BaseDamage = 110.0f; // Maximum raw damage
	StrikeParams.PoiseDamage = 80.0f;
	StrikeParams.ArmorPenetrationFraction = 0.40f;
	StrikeParams.StaminaCost = 35.0f;
	StrikeParams.RequiredGuardTag = FGameplayTag::RequestGameplayTag(FName("State.Stance.VomTag"));
	StrikeParams.NextGuardTag = FGameplayTag::RequestGameplayTag(FName("State.Stance.Pflug"));
	StrikeParams.ApexTimeSeconds = 0.65f;
	StrikeParams.WindowDurationSeconds = 0.15f;
}

UGA_AshenStrike_Mordhau::UGA_AshenStrike_Mordhau()
{
	StrikeParams.StrikeType = EAshenMasterCutType::Mordhau;
	StrikeParams.BaseDamage = 95.0f;
	StrikeParams.PoiseDamage = 120.0f; // Heavy blunt stagger
	StrikeParams.ArmorPenetrationFraction = 1.0f; // 100% Armor Penetration (Pure Blunt Plate Breaker)
	StrikeParams.StaminaCost = 32.0f;
	StrikeParams.RequiredGuardTag = FGameplayTag::RequestGameplayTag(FName("State.Stance.Mordhau"));
	StrikeParams.NextGuardTag = FGameplayTag::RequestGameplayTag(FName("State.Stance.VomTag"));
	StrikeParams.ApexTimeSeconds = 0.60f;
	StrikeParams.WindowDurationSeconds = 0.15f;
}
