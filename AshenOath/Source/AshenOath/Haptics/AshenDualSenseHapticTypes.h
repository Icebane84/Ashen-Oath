// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenDualSenseHapticTypes.generated.h"

/**
 * EHapticTriggerEffectMode
 * 
 * Defines the adaptive trigger behavior mode for PlayStation 5 / PC DualSense controllers.
 */
UENUM(BlueprintType)
enum class EHapticTriggerEffectMode : uint8
{
	Off UMETA(DisplayName = "Off / Standard Spring"),
	Feedback UMETA(DisplayName = "Continuous Feedback (Drag / Resistance)"),
	WeaponLockout UMETA(DisplayName = "Hard-Stop Mechanical Lockout (Will Struggle)"),
	VibrationSlope UMETA(DisplayName = "Vibrational Frequency Slope (Heartbeat / Tension)"),
	SteppedSpring UMETA(DisplayName = "Stepped Spring Tension (Garrett Wire Snare)")
};

/**
 * ETriggerPriorityLevel
 * 
 * Defines the arbitration priority for competing adaptive trigger demands.
 */
UENUM(BlueprintType)
enum class ETriggerPriorityLevel : uint8
{
	Priority3_AmbientSomatic UMETA(DisplayName = "Priority 3: Ambient Somatic Friction (0.10 - 0.35)"),
	Priority2_CombatStagger UMETA(DisplayName = "Priority 2: Combat Stagger / Poise Break (Spring Collapse)"),
	Priority1_DialogueWillStruggle UMETA(DisplayName = "Priority 1: Dialogue Will Struggle (100% Mechanical Lockout)")
};

/**
 * ETactileWhisperChannel
 * 
 * Defines the routing channel for audio directed to the controller speaker.
 */
UENUM(BlueprintType)
enum class ETactileWhisperChannel : uint8
{
	None UMETA(DisplayName = "None"),
	GarrettTactical UMETA(DisplayName = "Garrett Flank Whisper"),
	SerafinaPrayer UMETA(DisplayName = "Serafina Holy Inscription"),
	InnerVoiceDissonance UMETA(DisplayName = "Inner Voice Cognitive Whisper"),
	HeartbeatSomatic UMETA(DisplayName = "Somatic Pulse Rhythm")
};

/**
 * FDualSenseTriggerConfig
 * 
 * Configuration payload for active adaptive trigger resistance.
 */
USTRUCT(BlueprintType)
struct FDualSenseTriggerConfig
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Haptics")
	EHapticTriggerEffectMode Mode = EHapticTriggerEffectMode::Off;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Haptics")
	ETriggerPriorityLevel Priority = ETriggerPriorityLevel::Priority3_AmbientSomatic;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Haptics")
	float StartPosition = 0.0f; // 0.0 to 1.0 trigger travel

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Haptics")
	float ResistanceForce = 0.0f; // 0.0 to 1.0 stiffness

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Haptics")
	float VibrationFrequencyHz = 0.0f;
};

/**
 * FTactileWhisperPayload
 * 
 * Data packet for a companion whisper routed through controller speaker.
 */
USTRUCT(BlueprintType)
struct FTactileWhisperPayload
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Haptics")
	ETactileWhisperChannel Channel = ETactileWhisperChannel::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Haptics")
	FString DialogueLine = TEXT("");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Haptics")
	float VolumeMultiplier = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Haptics")
	bool bIncludeHapticTick = true;
};

// Multicast Delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTriggerConfigChanged, bool, bIsLeftTrigger, const FDualSenseTriggerConfig&, NewConfig);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTactileWhisperEmitted, const FTactileWhisperPayload&, Payload);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDirectionalTactilePulse, float, LeftIntensity, float, RightIntensity);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTriggerLockoutEngaged, bool, bEngaged);
