// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// ENGINE-SPEC-001 Canonical Soul Constellation Type Definitions

#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenSoulConstellationTypes.generated.h"

/** Stance disposition profile — how Kaelen approaches conflict */
UENUM(BlueprintType)
enum class EAshenStanceProfile : uint8
{
	Resolved_Protector,
	Reckless_Avenger,
	Cynical_Isolated,
	Fractured_Reactive
};

/** Empathic disposition profile — how Kaelen relates to others */
UENUM(BlueprintType)
enum class EAshenEmpathicProfile : uint8
{
	Open_Compassionate,
	Guarded_Transactional,
	Burned_Out,
	Dissociated_Hollow
};

/** Tactical cognitive profile — how Kaelen processes danger */
UENUM(BlueprintType)
enum class EAshenTacticalProfile : uint8
{
	Methodical_Calculated,
	Aggressive_Volatile,
	Evasive_Cautious,
	Paralyzed_Overwhelmed
};

/** Integration Debt escalation stages — ENGINE-SPEC-001 Section 2 */
UENUM(BlueprintType)
enum class EAshenIntegrationDebtStage : uint8
{
	Stable,         // 0.0 – 0.25: No systemic pressure
	LatentPressure, // 0.25 – 0.50: Subtle audio whispers, minor HUD shimmer
	MemoryBleed,    // 0.50 – 0.75: Whisper frequency doubles, companion dialogue shifts
	RuntimeNoise,   // 0.75 – 1.00: Parry window degrades, forced Heartstone prompt
	ForcedCollapse  // >= 1.00: InvokeIntegration(bForcedCollapse=true)
};

/** A single psychological imprint event feeding the FSoulStateVector */
USTRUCT(BlueprintType)
struct FAshenPsychologicalImprint
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Soul")
	FName ImprintID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Soul")
	float IntegrationDebtDelta = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Soul")
	float StanceWeightDelta = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Soul")
	float EmpathicWeightDelta = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Soul")
	float TacticalWeightDelta = 0.0f;
};

/** BehavioralProfile — semantic firewall layer sitting atop the raw FSoulStateVector */
USTRUCT(BlueprintType)
struct FAshenBehavioralProfile
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Soul")
	EAshenStanceProfile StanceProfile = EAshenStanceProfile::Resolved_Protector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Soul")
	EAshenEmpathicProfile EmpathicProfile = EAshenEmpathicProfile::Open_Compassionate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Soul")
	EAshenTacticalProfile TacticalProfile = EAshenTacticalProfile::Methodical_Calculated;
};

/** FAshenIdentityStateVector — ENGINE-SPEC-001 canonical 128-byte identity struct */
USTRUCT(BlueprintType)
struct FAshenIdentityStateVector
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Soul")
	float StanceWeight = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Soul")
	float EmpathicWeight = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Soul")
	float TacticalWeight = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Soul")
	float IntegrationDebt = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Soul")
	float ResolveScore = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Soul")
	FAshenBehavioralProfile CompiledProfile;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Soul")
	EAshenIntegrationDebtStage DebtStage = EAshenIntegrationDebtStage::Stable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Soul")
	int32 TotalImprintsProcessed = 0;
};

// Globally unique delegate names to prevent UHT collision across Batch #62 headers
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSoulStateVectorInvalidated, const FSoulStateVector&, NewStateVector);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnIntegrationDebtStageChanged, EAshenIntegrationDebtStage, NewDebtStage);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnIdentityCompilationComplete);
