// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "StateTreeTaskBase.h"
#include "FStateTreeTask_ShroudKnightPhase.generated.h"

class AAshenShroudKnight;

USTRUCT(BlueprintType)
struct ASHENOATH_API FStateTreeTask_ShroudKnightPhaseInstanceData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Parameter")
	float PhaseDuration = 4.0f;

	UPROPERTY(Transient)
	float ElapsedTime = 0.0f;

	UPROPERTY(Transient)
	TWeakObjectPtr<AAshenShroudKnight> CachedKnight;
};

/**
 * FStateTreeTask_ShroudKnightPhase
 *
 * StateTree task governing the Shroud-Knight's spectral wall-phasing shift.
 * Enables dither-shading translucency and wall penetration.
 */
USTRUCT(BlueprintType, meta = (DisplayName = "Ashen Shroud Knight Phase Shift"))
struct ASHENOATH_API FStateTreeTask_ShroudKnightPhase final : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

	typedef FStateTreeTask_ShroudKnightPhaseInstanceData FInstanceDataType;

	virtual const UScriptStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }

	virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const override;
	virtual EStateTreeRunStatus Tick(FStateTreeExecutionContext& Context, const float DeltaTime) const override;
	virtual void ExitState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const override;
};
