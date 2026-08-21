// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenSquadTacticalTypes.generated.h"

/**
 * ETacticalCommandType
 * 
 * Defines the strategic squad command ordered to a companion.
 */
UENUM(BlueprintType)
enum class ETacticalCommandType : uint8
{
	None UMETA(DisplayName = "None"),
	GarrettWireSnare UMETA(DisplayName = "Garrett: Wire Snare (Pin Target)"),
	SerafinaAegisShield UMETA(DisplayName = "Serafina: Aegis Bulwark (Intervene)"),
	LyraFlankVolley UMETA(DisplayName = "Lyra: Shadow Arrow Volley"),
	CoordinatedStrike UMETA(DisplayName = "Squad: Synchronized Tripartite Finisher"),
	FallBackToHeal UMETA(DisplayName = "Regroup: Fall Back to Guard Posture")
};

/**
 * ETemporalDilationState
 * 
 * Defines the active bullet-time time dilation mode.
 */
UENUM(BlueprintType)
enum class ETemporalDilationState : uint8
{
	Realtime UMETA(DisplayName = "Realtime (1.00x)"),
	TacticalSlowMo UMETA(DisplayName = "Tactical Bullet-Time (0.20x Dilation)"),
	ComboFreezeFrame UMETA(DisplayName = "Combo Impact Micro-Freeze (0.05x)")
};

/**
 * FSquadCommandEntry
 * 
 * Data packet representing a dispatched tactical companion order.
 */
USTRUCT(BlueprintType)
struct FSquadCommandEntry
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Tactics")
	ETacticalCommandType CommandType = ETacticalCommandType::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Tactics")
	FName TargetCompanionId = NAME_None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Tactics")
	FVector TargetWorldLocation = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Tactics")
	float CommandTimestamp = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Tactics")
	bool bIsExecuted = false;
};

/**
 * FTemporalComboExecutionState
 * 
 * Tracks the multi-character synchronized strike state.
 */
USTRUCT(BlueprintType)
struct FTemporalComboExecutionState
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Tactics")
	int32 ActiveParticipants = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Tactics")
	float ComboSyncWindowSeconds = 0.60f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Tactics")
	float DamageMultiplier = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Tactics")
	bool bIsSynchronized = false;
};

// Multicast Delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSquadCommandDispatched, const FSquadCommandEntry&, Command, bool, bSuccess);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTemporalDilationChanged, ETemporalDilationState, NewState, float, TimeDilationFactor);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCoOpComboTriggered, const FTemporalComboExecutionState&, ComboState);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTacticalWheelVisibilityChanged, bool, bIsVisible);
