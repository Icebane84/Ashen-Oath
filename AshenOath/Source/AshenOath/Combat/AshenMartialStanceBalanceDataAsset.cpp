// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenMartialStanceBalanceDataAsset.h"

UAshenMartialStanceBalanceDataAsset::UAshenMartialStanceBalanceDataAsset()
{
	// 1. Vom Tag: High Wrath Guard Default
	VomTagConfig.Stance = EOathbringerMartialStance::VomTag_HighWrath;
	VomTagConfig.DamageMultiplier = 1.40f;
	VomTagConfig.PoiseDamageMultiplier = 1.40f;
	VomTagConfig.StaminaCost = 35.0f;
	VomTagConfig.ParryWindowSeconds = 0.08f;
	VomTagConfig.ArmorPenetrationPercent = 0.20f;
	VomTagConfig.RunicSeamColor = FLinearColor(1.0f, 0.15f, 0.05f, 1.0f); // Crimson

	// 2. Pflug: Low Plow Guard Default
	PflugConfig.Stance = EOathbringerMartialStance::Pflug_LowPlow;
	PflugConfig.DamageMultiplier = 1.00f;
	PflugConfig.PoiseDamageMultiplier = 0.90f;
	PflugConfig.StaminaCost = 14.0f; // -30% stamina
	PflugConfig.ParryWindowSeconds = 0.10f;
	PflugConfig.ArmorPenetrationPercent = 0.35f;
	PflugConfig.RunicSeamColor = FLinearColor(0.9f, 0.95f, 1.0f, 1.0f); // White Flame

	// 3. Ochs: Crown Guard Default
	OchsConfig.Stance = EOathbringerMartialStance::Ochs_CrownGuard;
	OchsConfig.DamageMultiplier = 1.10f;
	OchsConfig.PoiseDamageMultiplier = 1.15f;
	OchsConfig.StaminaCost = 20.0f;
	OchsConfig.ParryWindowSeconds = 0.22f; // +0.12s parry leniency
	OchsConfig.ArmorPenetrationPercent = 0.15f;
	OchsConfig.RunicSeamColor = FLinearColor(1.0f, 0.85f, 0.2f, 1.0f); // Gold

	// 4. Mordhau: Half-Sword Default
	MordhauConfig.Stance = EOathbringerMartialStance::Mordhau_HalfSword;
	MordhauConfig.DamageMultiplier = 1.25f;
	MordhauConfig.PoiseDamageMultiplier = 1.75f; // +75% poise shatter
	MordhauConfig.StaminaCost = 28.0f;
	MordhauConfig.ParryWindowSeconds = 0.10f;
	MordhauConfig.ArmorPenetrationPercent = 1.00f; // 100% Armor Penetration
	MordhauConfig.RunicSeamColor = FLinearColor(0.35f, 0.1f, 0.6f, 1.0f); // Umbral
}

FOathbringerStanceKinematics UAshenMartialStanceBalanceDataAsset::GetKinematicsForStance(EOathbringerMartialStance Stance) const
{
	FOathbringerStanceKinematics OutKinematics;

	switch (Stance)
	{
	case EOathbringerMartialStance::VomTag_HighWrath:
		OutKinematics = VomTagConfig;
		break;
	case EOathbringerMartialStance::Pflug_LowPlow:
		OutKinematics = PflugConfig;
		break;
	case EOathbringerMartialStance::Ochs_CrownGuard:
		OutKinematics = OchsConfig;
		break;
	case EOathbringerMartialStance::Mordhau_HalfSword:
	default:
		OutKinematics = MordhauConfig;
		break;
	}

	// Boundary Safety Clamps to ensure balance changes cannot break the loop
	OutKinematics.Stance = Stance;
	OutKinematics.DamageMultiplier = FMath::Clamp(OutKinematics.DamageMultiplier, 0.10f, 10.0f);
	OutKinematics.PoiseDamageMultiplier = FMath::Clamp(OutKinematics.PoiseDamageMultiplier, 0.10f, 10.0f);
	OutKinematics.StaminaCost = FMath::Clamp(OutKinematics.StaminaCost, 1.0f, 200.0f);
	OutKinematics.ParryWindowSeconds = FMath::Clamp(OutKinematics.ParryWindowSeconds, 0.01f, 2.0f);
	OutKinematics.ArmorPenetrationPercent = FMath::Clamp(OutKinematics.ArmorPenetrationPercent, 0.0f, 1.0f);

	return OutKinematics;
}
