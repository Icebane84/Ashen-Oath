// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenCombatEcosystemTypes.generated.h"

UENUM(BlueprintType)
enum class EBestiaryArchetype : uint8
{
	ParasiticMirror          UMETA(DisplayName = "Parasitic Mirror (Umbral Symbiote)"),
	PlanetaryImmuneResponse  UMETA(DisplayName = "Planetary Immune Response (Cinder-Wyrm)"),
	VoidPredator             UMETA(DisplayName = "Void Predator (Veil-Hound / Aether-Weaver)"),
	ChaosPredator            UMETA(DisplayName = "Chaos Predator (Abyssal Sleeper / Sorrow-Leech)")
};

UENUM(BlueprintType)
enum class EEcosystemModeReaction : uint8
{
	TranquilityBuff  UMETA(DisplayName = "Aura of Tranquility (Calming Buff)"),
	ShadowedPanic    UMETA(DisplayName = "Shadowed Terror (Destructive Panic / Frenzy)"),
	FlameAttraction  UMETA(DisplayName = "Fatal Light Attraction (Stunned / Lured)"),
	DespairParasite  UMETA(DisplayName = "Despair Implantation (Aggressive Parasite)")
};

UENUM(BlueprintType)
enum class EBossPuzzlePhase : uint8
{
	Phase1_ObservationStalemate UMETA(DisplayName = "Phase 1: Observation / The Stalemate"),
	Phase2_RoleBreakthrough     UMETA(DisplayName = "Phase 2: Breakthrough / Role Execution"),
	Phase3_ResonanceSynthesis   UMETA(DisplayName = "Phase 3: Synthesis / Final Resonance Blow")
};

USTRUCT(BlueprintType)
struct FTAM001MemoryWeights
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | TAM")
	float RecencyWeight = 1.0f; // Current performance weight

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | TAM")
	float ConsistencyScore = 0.5f; // Frequency of clean teamwork (0.0 to 1.0)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | TAM")
	float SeverityImpact = 0.0f; // Failure severity penalty (0.0 to 1.0)

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | TAM")
	bool bIsSymbioticResonanceUnlocked = false;
};
