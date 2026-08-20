// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "StateTreeTaskBase.h"
#include "AshenOathTrustTypes.h"
#include "FStateTreeTask_CompanionSupport.generated.h"

class UAshenCompanionAIComponent;
class UAshenTraumaMatrixComponent;

/** PAA V2.1 Encounter Tier classification */
UENUM(BlueprintType)
enum class EAshenEncounterTier : uint8
{
	Tier1_Pressure    UMETA(DisplayName = "Tier I — Pressure"),
	Tier2_Trauma      UMETA(DisplayName = "Tier II — Trauma"),
	Tier3_Revelation  UMETA(DisplayName = "Tier III — Revelation")
};

/** PAA V2.1 Phase 5 Philosophical Resolution State */
UENUM(BlueprintType)
enum class EAshenResolutionState : uint8
{
	Unresolved          UMETA(DisplayName = "Question Unresolved"),
	EnemyProvedCorrect  UMETA(DisplayName = "Enemy Proved Correct"),
	PartialValidation   UMETA(DisplayName = "Partial Validation"),
	EnemyDisproved      UMETA(DisplayName = "Enemy Disproved")
};

/** Instance data for FStateTreeTask_CompanionSupport */
USTRUCT(BlueprintType)
struct ASHENOATH_API FStateTreeTask_CompanionSupportInstanceData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Input")
	EAshenEncounterTier EncounterTier = EAshenEncounterTier::Tier1_Pressure;

	UPROPERTY(EditAnywhere, Category = "Input")
	EAshenOathCompanion TargetCompanion = EAshenOathCompanion::Kaelen;

	UPROPERTY(Transient)
	EAshenResolutionState ResolutionState = EAshenResolutionState::Unresolved;

	UPROPERTY(Transient)
	TWeakObjectPtr<UAshenCompanionAIComponent> CachedCompanionAI;

	UPROPERTY(Transient)
	float EncounterElapsedTime = 0.0f;
};

/**
 * FStateTreeTask_CompanionSupport
 *
 * PAA V2.1-aware StateTree task driving companion AI behavioral routing
 * based on Encounter Tier pressure and tracking Phase 5 Resolution State.
 *
 * - Tier I (Pressure): Routes companion to OffensiveSupport
 * - Tier II (Trauma): Routes companion to TacticalTriage
 * - Tier III (Revelation): Routes companion to UnchainedContainment + RecoveryAnchoring
 */
USTRUCT(BlueprintType, meta = (DisplayName = "Ashen Companion Support (PAA V2.1)"))
struct ASHENOATH_API FStateTreeTask_CompanionSupport final : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

	typedef FStateTreeTask_CompanionSupportInstanceData FInstanceDataType;

	virtual const UScriptStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }

	virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const override;
	virtual EStateTreeRunStatus Tick(FStateTreeExecutionContext& Context, const float DeltaTime) const override;
	virtual void ExitState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const override;
};
