// Copyright Phoenix Protocol. All rights reserved.

#include "AshenGameSettings.h"

UAshenGameSettings::UAshenGameSettings()
{
	GlobalKnockbackMultiplier = 1.0f;
	HitstopDurationMultiplier = 1.0f;
	SanityDrainProximityMultiplier = 1.0f;
	CameraTraumaMultiplier = 1.0f;

	CorruptionTransitionSpeed = 2.0f;

	OathbringerPureColor = FLinearColor(0.0f, 1.0f, 0.84f);
	OathbringerCorruptColor = FLinearColor(0.545f, 0.0f, 0.0f);
	OathbringerCorruptionThreshold = 0.8f;
	OathbringerLightIntensity = 500.0f;
	OathbringerWidthMinScale = 1.25f;
	OathbringerWidthMaxScale = 2.7f;
	OathbringerLengthMinScale = 1.25f;
	OathbringerLengthMaxScale = 1.8f;

	PlayerInteractionDistance = 300.0f;
	PlayerInteractionInterval = 0.1f;

	AIEvaluatePreferredDistance = 300.0f;
	AIEvaluateCircuitBreakerThreshold = 0.15f;
	AIEvaluateDistanceDecayFactor = 0.001f;

	BaseDodgeForce = 1500.0f;
	BaseDodgeDuration = 0.4f;
	BaseDodgeStaminaCost = 20.0f;
	DamageTraumaAmount = 0.4f;
	BaseNormalFOV = 75.0f;
	BaseSprintFOV = 85.0f;
	BaseFOVSmoothSpeed = 10.0f;
	BaseTraumaDecay = 2.0f;

	LockOnRange = 1500.0f;
	RotationInterpolationSpeed = 5.0f;

	ManifestationMinThreshold = 25.0f;
	ManifestationMediumThreshold = 50.0f;
	ManifestationHighThreshold = 80.0f;
	ManifestationMaxDistortion = 0.4f;
	ManifestationMediumInterval = 8.0f;
	ManifestationHighInterval = 5.0f;
	ManifestationCriticalInterval = 2.5f;

	ProjectilePoolSize = 30;
	DamageTextPoolSize = 5;
	DamageTextRandomOffsetRange = 50.0f;
	DamageTextHeightOffset = 120.0f;

	WhispererProximityRange = 800.0f;
	WhispererSanityDrainRate = 4.0f;
	WhispererMinInterval = 3.0f;
	WhispererMaxInterval = 6.0f;

	InputBufferValidityDuration = 0.3f;
}
