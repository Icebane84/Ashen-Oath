// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenCrisisTypes.generated.h"

UENUM(BlueprintType)
enum class EAshenCrisisStage : uint8
{
	Inactive,
	TimeDilationStart,      // 0.0s - 10% speed
	PhysicsSimulationFreeze, // 0.2s - cloth/hair freeze
	HapticSilence,          // 0.4s - absolute rumble absence
	HeartbeatPulse,         // 0.6s - wet heartbeat audio
	VisionCollapse,         // 0.8s - peripheral ocular shadow
	MarkRunePulse,          // 1.0s - in-world forearm mark
	TriggerResistanceLock,  // 1.2s - DualSense trigger lock
	ParasiteWhisper,        // 1.5s - compassionate parasite audio
	DecisionWindowActive    // 2.0s - full realization choice
};

UENUM(BlueprintType)
enum class EAshenCrisisResolutionChoice : uint8
{
	Pending,
	PathA_SurrenderDevilsBargain,
	PathB_RestraintWhiteFlame,
	DefaultInstinctHesitation
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCrisisStageShifted, EAshenCrisisStage, PreviousStage, EAshenCrisisStage, NewStage);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCrisisResolved, EAshenCrisisResolutionChoice, Choice);
