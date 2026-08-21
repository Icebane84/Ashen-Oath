// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenScenario4WhisperwoodTypes.generated.h"

/**
 * EWhisperwoodEventTier
 * 
 * Environmental and psychological event escalation in Whisperwood.
 */
UENUM(BlueprintType)
enum class EWhisperwoodEventTier : uint8
{
	GentlePurpleMist UMETA(DisplayName = "Gentle Purple Mist (Baseline Distortion)"),
	WhisperingWinds UMETA(DisplayName = "Whispering Winds (Auditory Mirage)"),
	NightmareIncursion UMETA(DisplayName = "Nightmare Incursion (Phantom Entities)")
};

/**
 * ECompanionGroundingState
 * 
 * Result of checking companion skeletal joint alignment against a perceived threat.
 */
UENUM(BlueprintType)
enum class ECompanionGroundingState : uint8
{
	VerifiedPhysicalThreat UMETA(DisplayName = "Verified Physical Threat (Companion Targeted)"),
	InvalidatedHallucination UMETA(DisplayName = "Invalidated Hallucination (Phantom Mirage)"),
	PendingAlignment UMETA(DisplayName = "Pending Alignment Check")
};

/**
 * FWhisperwoodMistState
 * 
 * Volumetric mist and chromatic distortion parameters.
 */
USTRUCT(BlueprintType)
struct FWhisperwoodMistState
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario4")
	float PurpleMistDensity = 0.50f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario4")
	float ChromaticAberrationIntensity = 1.0f; // 0.0 to 5.0

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario4")
	float SootLayerOpacity = 0.0f; // 0.0 to 1.0

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario4")
	int32 UnlockedCognitiveLoci = 0;
};

/**
 * FCompanionGroundingVerificationContext
 * 
 * Contextual verification data when Kaelen checks companion orientation.
 */
USTRUCT(BlueprintType)
struct FCompanionGroundingVerificationContext
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario4")
	FName PerceivedThreatId = NAME_None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario4")
	FVector ThreatLocation = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario4")
	bool bCompanionHasLineOfSight = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario4")
	bool bCompanionIsTargetingThreat = false;
};

// Multicast Delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGroundingCheckExecuted, const FName&, ThreatId, ECompanionGroundingState, GroundingResult);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSootWiped, float, RemainingSootOpacity);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCognitiveLocusDiscovered, const FName&, LocusId, int32, TotalLoci);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWhisperwoodCleared, bool, bSanityMaintained);
