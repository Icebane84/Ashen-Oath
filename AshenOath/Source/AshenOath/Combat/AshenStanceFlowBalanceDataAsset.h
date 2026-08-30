// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Combat/AshenOathbringerStanceTypes.h"
#include "AshenStanceFlowBalanceDataAsset.generated.h"

/**
 * UAshenStanceFlowBalanceDataAsset
 *
 * Data-driven configuration asset for Greatsword Stance Flow, 115 BPM Flow Glint,
 * and Dual-Sigil Companion Resonance (CONVERGENCE-SPEC-101 / PRS-001-ENG-STANCE-101).
 * Adheres strictly to the Zero-Recompile Protocol with runtime safety clamps.
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenStanceFlowBalanceDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UAshenStanceFlowBalanceDataAsset();

	/** Vom Tag Poise damage multiplier (Default 1.40x) */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stance|VomTag", meta = (ClampMin = "1.0", ClampMax = "2.5"))
	float VomTagPoiseMultiplier = 1.40f;

	/** Pflug Stamina discount ratio (Default 0.30 -> -30% stamina cost) */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stance|Pflug", meta = (ClampMin = "0.0", ClampMax = "0.60"))
	float PflugStaminaDiscount = 0.30f;

	/** Ochs Parry frame window bonus in seconds (Default +0.12s) */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stance|Ochs", meta = (ClampMin = "0.02", ClampMax = "0.30"))
	float OchsParryWindowBonus = 0.12f;

	/** Mordhau Armor penetration scalar (Default 1.00 -> 100%) */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stance|Mordhau", meta = (ClampMin = "0.50", ClampMax = "1.0"))
	float MordhauArmorPenetration = 1.00f;

	/** Flow Glint timing window tolerance in seconds (Default 0.15s at 115 BPM) */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Timing|FlowGlint", meta = (ClampMin = "0.08", ClampMax = "0.30"))
	float FlowGlintDurationSeconds = 0.15f;

	/** Flow Glint kinetic animation speed multiplier (Default 1.25x -> +25%) */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Timing|FlowGlint", meta = (ClampMin = "1.0", ClampMax = "1.75"))
	float FlowGlintSpeedMultiplier = 1.25f;

	/** Flow Glint forward translation velocity boost (Default +15%) */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Timing|FlowGlint", meta = (ClampMin = "1.0", ClampMax = "1.50"))
	float FlowGlintTranslationBoost = 1.15f;

	/** Companion proximity threshold for Dual-Sigil resonance (Default 200.0 uu) */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Trinity|Proximity", meta = (ClampMin = "100.0", ClampMax = "500.0"))
	float CompanionPocketRadius = 200.0f;

	/** Garrett Twin Flank Shred posture trauma multiplier (Default 1.80x) */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Trinity|Garrett", meta = (ClampMin = "1.20", ClampMax = "3.0"))
	float GarrettFlankMultiplier = 1.80f;

	/** Serafina Aegis Harmonic Pulse stamina recovery surge (Default +35.0 stamina) */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Trinity|Serafina", meta = (ClampMin = "15.0", ClampMax = "75.0"))
	float SerafinaStaminaSurge = 35.0f;

	/** Companion Trust reward committed on successful Dual-Sigil resonance (Default +0.05) */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Trinity|Trust", meta = (ClampMin = "0.01", ClampMax = "0.20"))
	float DualSigilTrustReward = 0.05f;
};
