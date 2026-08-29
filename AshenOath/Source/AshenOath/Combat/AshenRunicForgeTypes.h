// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenRunicForgeTypes.generated.h"

/**
 * EOathbringerAscensionTier
 * 
 * Metallurgical and spiritual evolution tiers of Oathbringer.
 */
UENUM(BlueprintType)
enum class EOathbringerAscensionTier : uint8
{
	Tier1_DullNightsteel   UMETA(DisplayName = "Tier 1: Dull Nightsteel (1.0x Base Dmg, 100 Flow Cap)"),
	Tier2_AwakenedFuller   UMETA(DisplayName = "Tier 2: Awakened Fuller (1.1x Dmg, 150 Flow Cap, Flow Glint)"),
	Tier3_SunderedSovereign UMETA(DisplayName = "Tier 3: Sundered Sovereign (1.2x Dmg, 4 Sigil Sockets Unlocked)"),
	Tier4_EldrinsCrucible  UMETA(DisplayName = "Tier 4: Eldrin's Crucible (1.3x Dmg, 1.50 Soot Battery Cap)"),
	Tier5_GodslayerApex    UMETA(DisplayName = "Tier 5: Godslayer Apex (1.5x Dmg, 0.0s Stance Latency, White Flame Aura)")
};

/**
 * EGuardSigilSocket
 * 
 * The 4 dedicated martial guard sigil sockets along Oathbringer's fuller seam.
 */
UENUM(BlueprintType)
enum class EGuardSigilSocket : uint8
{
	VomTagSocket  UMETA(DisplayName = "Vom Tag Socket (High Wrath - Cleaves)"),
	PflugSocket   UMETA(DisplayName = "Pflug Socket (Low Plow - Thrusts & Sprints)"),
	OchsSocket    UMETA(DisplayName = "Ochs Socket (Crown Guard - Parries & Counters)"),
	MordhauSocket UMETA(DisplayName = "Mordhau Socket (Half-Sword / Pommel - Plate Crushing)")
};

/**
 * ESigilResonanceEffect
 * 
 * Ancient runic glyphs that can be socketed into Oathbringer's guards.
 */
UENUM(BlueprintType)
enum class ESigilResonanceEffect : uint8
{
	None              UMETA(DisplayName = "None (Empty Socket)"),
	ShatteredColossus UMETA(DisplayName = "Sigil of the Shattered Colossus (600uu Terrain Fissure, +150 Poise Dmg)"),
	ZephyrGale        UMETA(DisplayName = "Sigil of the Zephyr Gale (400uu Aerodynamic Vacuum Suction)"),
	SunkenSun         UMETA(DisplayName = "Sigil of the Sunken Sun (+0.15s Parry Leniency, 2.5s Radial Blind)"),
	GravimetricCore   UMETA(DisplayName = "Sigil of the Gravimetric Core (100% Armor Penetration, Gravity Pulse)")
};

/**
 * FGuardSigilSocketData
 * 
 * Inscription state for a single guard socket.
 */
USTRUCT(BlueprintType)
struct FGuardSigilSocketData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|RunicForge")
	EGuardSigilSocket SocketType = EGuardSigilSocket::VomTagSocket;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|RunicForge")
	ESigilResonanceEffect InscribedSigil = ESigilResonanceEffect::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|RunicForge")
	bool bSocketUnlocked = true;
};

/**
 * FOathbringerEvolutionState
 * 
 * Master progression state of Oathbringer.
 */
USTRUCT(BlueprintType)
struct FOathbringerEvolutionState
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|RunicForge")
	EOathbringerAscensionTier AscensionTier = EOathbringerAscensionTier::Tier1_DullNightsteel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|RunicForge")
	float BaseDamageMultiplier = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|RunicForge")
	float MaxFlowChargeCap = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|RunicForge")
	int32 UnlockedSocketsCount = 0;
};

/**
 * FFlowResonanceResult
 * 
 * Metrics calculated when executing a hybrid dual-sigil finisher strike.
 */
USTRUCT(BlueprintType)
struct FFlowResonanceResult
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|RunicForge")
	bool bResonanceTriggered = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|RunicForge")
	float HybridDamageMultiplier = 1.40f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|RunicForge")
	float FissureRadiusUU = 600.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|RunicForge")
	float VacuumSuctionRadiusUU = 400.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|RunicForge")
	FText ResonanceDescription;
};

// Multicast Delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnOathbringerTierAscended, EOathbringerAscensionTier, NewTier, const FOathbringerEvolutionState&, State);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGuardSigilInscribed, EGuardSigilSocket, Socket, ESigilResonanceEffect, InscribedSigil);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFlowResonanceFinisherExecuted, const FFlowResonanceResult&, Result);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRunicSeamGlyphsUpdated, EGuardSigilSocket, ActiveGuard);
