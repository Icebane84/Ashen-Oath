// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Orchestration/AshenMacroSystemicContractTypes.h"
#include "AshenRunicForgeTypes.generated.h"

UENUM(BlueprintType)
enum class EOathbringerAscensionTier : uint8
{
	Tier1_DullNightsteel = 0 UMETA(DisplayName = "Tier 1: The Burdened Iron (Dull Nightsteel)"),
	Tier2_AwakenedFuller = 1 UMETA(DisplayName = "Tier 2: The Resonant Fuller (Awakened Fuller)"),
	Tier3_SunderedSovereign = 2 UMETA(DisplayName = "Tier 3: Sundered Sovereign"),
	Tier4_EldrinsCrucible = 3 UMETA(DisplayName = "Tier 4: Eldrin's Crucible"),
	Tier5_GodslayerApex = 4 UMETA(DisplayName = "Tier 5: Zenith Sovereign (Godslayer Apex)"),

	BurdenedIron = Tier1_DullNightsteel,
	AwakenedFuller = Tier2_AwakenedFuller,
	SunderedSovereign = Tier3_SunderedSovereign,
	EldrinsCrucible = Tier4_EldrinsCrucible,
	ZenithSovereign = Tier5_GodslayerApex
};

UENUM(BlueprintType)
enum class EGuardSigilSocket : uint8
{
	VomTagSocket = 0 UMETA(DisplayName = "High Guard (Vom Tag)"),
	PflugSocket = 1 UMETA(DisplayName = "Plow Guard (Pflug)"),
	OchsSocket = 2 UMETA(DisplayName = "Window Guard (Ochs)"),
	MordhauSocket = 3 UMETA(DisplayName = "Murder Stroke (Mordhau)"),

	VomTag = VomTagSocket,
	Pflug = PflugSocket,
	Ochs = OchsSocket,
	Mordhau = MordhauSocket
};

UENUM(BlueprintType)
enum class ESigilResonanceEffect : uint8
{
	None = 0,
	ShatteredColossus = 1 UMETA(DisplayName = "Colossus Rupture / Shattered Colossus"),
	ZephyrGale = 2 UMETA(DisplayName = "Zephyr Gale / Vacuum Thrust"),
	SunkenSun = 3 UMETA(DisplayName = "Sunken Sun / Aegis White Flame"),
	GravimetricCore = 4 UMETA(DisplayName = "Gravimetric Core / Pommel Shatter"),

	ColossusRuptureCleave = ShatteredColossus,
	ZephyrVacuumThrust = ZephyrGale,
	AegisWhiteFlameParry = SunkenSun,
	GravimetricPommelShatter = GravimetricCore
};

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

USTRUCT(BlueprintType)
struct FGuardSigilSocketData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|RunicForge")
	EGuardSigilSocket SocketType = EGuardSigilSocket::VomTagSocket;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|RunicForge")
	ESigilResonanceEffect InscribedSigil = ESigilResonanceEffect::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|RunicForge")
	bool bSocketUnlocked = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|RunicForge")
	bool bIsUnlocked = false;
};

USTRUCT(BlueprintType)
struct FFlowResonanceResult
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|RunicForge")
	bool bResonanceTriggered = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|RunicForge")
	float HybridDamageMultiplier = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|RunicForge")
	float FissureRadiusUU = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|RunicForge")
	float VacuumSuctionRadiusUU = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|RunicForge")
	FText ResonanceDescription;
};

USTRUCT(BlueprintType)
struct FMemoryEchoSocketBinding
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|RunicForge")
	FGuid BoundMemoryImprintId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|RunicForge")
	EOntologicalLens AppliedLens = EOntologicalLens::Uncompiled;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|RunicForge")
	EGuardSigilSocket TargetSocket = EGuardSigilSocket::VomTagSocket;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|RunicForge")
	FGameplayTag GrantedCombatTrait;
};

USTRUCT(BlueprintType)
struct FOathbringerMorphologyState
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Morphology")
	EOathbringerAscensionTier CurrentTier = EOathbringerAscensionTier::Tier1_DullNightsteel;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Morphology")
	TMap<EGuardSigilSocket, FMemoryEchoSocketBinding> SocketBindings;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Morphology")
	bool bIsFlowGlintActive = false;
};

USTRUCT(BlueprintType)
struct FHybridFinisherPayload
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Ashen|Finisher")
	FGameplayTag FinisherTag;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen|Finisher")
	float PoiseBreakMultiplier = 1.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen|Finisher")
	float DebtPurgeDelta = 0.0f;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnOathbringerTierAscended, EOathbringerAscensionTier, NewTier, const FOathbringerEvolutionState&, NewState);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGuardSigilInscribed, EGuardSigilSocket, Socket, ESigilResonanceEffect, Sigil);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFlowResonanceFinisherExecuted, const FFlowResonanceResult&, Result);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRunicSeamGlyphsUpdated, EGuardSigilSocket, ActiveSocket);
