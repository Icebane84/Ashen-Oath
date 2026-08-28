// Copyright Phoenix Protocol. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "AshenGameSettings.generated.h"

/**
 * UAshenGameSettings
 * Unified game configurations exposed to Project Settings -> Game -> Ashen Settings.
 * Driven by DefaultGame.ini.
 */
UCLASS(Config=Game, DefaultConfig, meta=(DisplayName="Ashen Settings"))
class ASHENOATH_API UAshenGameSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UAshenGameSettings();

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Combat", meta = (ClampMin = "0.0"))
	float GlobalKnockbackMultiplier;

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Combat", meta = (ClampMin = "0.0"))
	float HitstopDurationMultiplier;

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Horror", meta = (ClampMin = "0.0"))
	float SanityDrainProximityMultiplier;

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Camera", meta = (ClampMin = "0.0"))
	float CameraTraumaMultiplier;

	/** Visual corruption transition speed for Kaelen (Dark Mode swap speed) */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Horror", meta = (ClampMin = "0.1"))
	float CorruptionTransitionSpeed;

	/** Pure state emission light and channel glow color for Oathbringer */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Oathbringer")
	FLinearColor OathbringerPureColor;

	/** Corrupt state emission light and channel glow color for Oathbringer */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Oathbringer")
	FLinearColor OathbringerCorruptColor;

	/** Threshold (0.0 - 1.0) above which Oathbringer pulses and behaves erratically */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Oathbringer", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float OathbringerCorruptionThreshold;

	/** Base light emission component intensity for Oathbringer */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Oathbringer", meta = (ClampMin = "0.0"))
	float OathbringerLightIntensity;

	/** Minimum/Light width (X/Y axis) scale multiplier for Oathbringer */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Oathbringer", meta = (ClampMin = "0.1"))
	float OathbringerWidthMinScale;

	/** Maximum/Dark width (X/Y axis) scale multiplier (Guts massive greatsword slab) */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Oathbringer", meta = (ClampMin = "0.1"))
	float OathbringerWidthMaxScale;

	/** Minimum/Light length (Z axis) scale multiplier for Oathbringer */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Oathbringer", meta = (ClampMin = "0.1"))
	float OathbringerLengthMinScale;

	/** Maximum/Dark length (Z axis) scale multiplier for Oathbringer greatsword */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Oathbringer", meta = (ClampMin = "0.1"))
	float OathbringerLengthMaxScale;

	/** Maximum raycast distance for player interactions */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Interaction", meta = (ClampMin = "0.0"))
	float PlayerInteractionDistance;

	/** Line trace query polling frequency interval (seconds) */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Interaction", meta = (ClampMin = "0.01"))
	float PlayerInteractionInterval;

	/** Target range for action evaluation task preferred target distance */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "AI", meta = (ClampMin = "0.0"))
	float AIEvaluatePreferredDistance;

	/** Circuit breaker utility threshold under which evaluation fails out */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "AI", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float AIEvaluateCircuitBreakerThreshold;

	/** Distance score decay scalar parameter for AI Action evaluation */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "AI", meta = (ClampMin = "0.0001"))
	float AIEvaluateDistanceDecayFactor;

	/** Base dodge impulse launch force */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Movement", meta = (ClampMin = "100.0"))
	float BaseDodgeForce;

	/** Base duration (seconds) of invincibility/dodge state */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Movement", meta = (ClampMin = "0.05"))
	float BaseDodgeDuration;

	/** Stamina cost consumed upon executing a dodge roll */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Movement", meta = (ClampMin = "0.0"))
	float BaseDodgeStaminaCost;

	/** Camera trauma amount added when wielder receives damage */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Camera", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float DamageTraumaAmount;

	/** Default camera Field of View in normal exploration */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Camera", meta = (ClampMin = "30.0", ClampMax = "120.0"))
	float BaseNormalFOV;

	/** Extended camera Field of View during sprint or dodge action speeds */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Camera", meta = (ClampMin = "30.0", ClampMax = "120.0"))
	float BaseSprintFOV;

	/** Interpolation velocity factor for camera Field of View shifts */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Camera", meta = (ClampMin = "0.1"))
	float BaseFOVSmoothSpeed;

	/** Screen-shake trauma decay speed rate */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Camera", meta = (ClampMin = "0.1"))
	float BaseTraumaDecay;

	/** Maximum lock-on distance for target tracking scanning */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Combat", meta = (ClampMin = "100.0"))
	float LockOnRange;

	/** Camera interpolation speed during active lock-on tracking */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Combat", meta = (ClampMin = "0.1"))
	float RotationInterpolationSpeed;

	/** Minimum wielder instability (100 - Sanity) threshold to start minor cognitive hallucinations */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Horror", meta = (ClampMin = "0.0", ClampMax = "100.0"))
	float ManifestationMinThreshold;

	/** Medium wielder instability threshold to escalate cognitive hallucinations */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Horror", meta = (ClampMin = "0.0", ClampMax = "100.0"))
	float ManifestationMediumThreshold;

	/** High wielder instability threshold to trigger critical cognitive hallucinations */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Horror", meta = (ClampMin = "0.0", ClampMax = "100.0"))
	float ManifestationHighThreshold;

	/** Reality distortion post-process overlay strength scalar parameter */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Horror", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float ManifestationMaxDistortion;

	/** Hallucination check event interval at medium instability levels (seconds) */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Horror", meta = (ClampMin = "0.1"))
	float ManifestationMediumInterval;

	/** Hallucination check event interval at high instability levels (seconds) */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Horror", meta = (ClampMin = "0.1"))
	float ManifestationHighInterval;

	/** Hallucination check event interval at critical instability levels (seconds) */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Horror", meta = (ClampMin = "0.1"))
	float ManifestationCriticalInterval;

	/** Total allocated actor count for pre-spawned projectile pool */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Pooling", meta = (ClampMin = "1"))
	int32 ProjectilePoolSize;

	/** Total allocated actor count for pre-spawned floating damage text pool */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Pooling", meta = (ClampMin = "1"))
	int32 DamageTextPoolSize;

	/** Random dispersion radius on the XY horizontal plane for spawned damage text positioning */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Pooling", meta = (ClampMin = "0.0"))
	float DamageTextRandomOffsetRange;

	/** Vertical elevation spawn height delta offset (Z axis) for floating damage text */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Pooling", meta = (ClampMin = "0.0"))
	float DamageTextHeightOffset;

	/** Whisperer shadow enemy passive proximity drain range radius */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Horror", meta = (ClampMin = "10.0"))
	float WhispererProximityRange;

	/** Whisperer shadow enemy base sanity drain rate per second */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Horror", meta = (ClampMin = "0.0"))
	float WhispererSanityDrainRate;

	/** Minimum random seconds interval before whisperer shadow enemy whispers again */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Horror", meta = (ClampMin = "0.1"))
	float WhispererMinInterval;

	/** Maximum random seconds interval before whisperer shadow enemy whispers again */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Horror", meta = (ClampMin = "0.1"))
	float WhispererMaxInterval;

	/** Combat action queue validity lifespan duration in seconds */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Combat", meta = (ClampMin = "0.01"))
	float InputBufferValidityDuration;
};
