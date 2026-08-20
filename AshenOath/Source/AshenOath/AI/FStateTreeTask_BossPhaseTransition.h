// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "StateTreeTaskBase.h"
#include "FStateTreeTask_CompanionSupport.h"
#include "FStateTreeTask_BossPhaseTransition.generated.h"

USTRUCT(BlueprintType)
struct ASHENOATH_API FStateTreeTask_BossPhaseTransitionInstanceData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Parameter")
	EAshenEncounterTier NextEncounterTier = EAshenEncounterTier::Tier2_Trauma;

	UPROPERTY(EditAnywhere, Category = "Parameter")
	float TransitionDuration = 3.0f;

	UPROPERTY(Transient)
	float ElapsedTime = 0.0f;

	UPROPERTY(Transient)
	bool bPhaseInitialized = false;
};

/**
 * FStateTreeTask_BossPhaseTransition
 *
 * StateTree task governing boss phase transitions (e.g. Ashen Abomination bark armor strip -> trauma frenzy; Shroud Knight paranoia storm).
 * Updates PAA V2.1 encounter tier via UAshenPAAMasterOrchestrator and enforces invulnerability windows.
 */
USTRUCT(BlueprintType, meta = (DisplayName = "Ashen Boss Phase Transition"))
struct ASHENOATH_API FStateTreeTask_BossPhaseTransition final : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

	typedef FStateTreeTask_BossPhaseTransitionInstanceData FInstanceDataType;

	virtual const UScriptStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }

	virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const override;
	virtual EStateTreeRunStatus Tick(FStateTreeExecutionContext& Context, const float DeltaTime) const override;
	virtual void ExitState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const override;
};
