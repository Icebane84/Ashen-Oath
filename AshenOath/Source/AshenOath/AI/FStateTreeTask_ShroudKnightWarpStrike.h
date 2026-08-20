// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "StateTreeTaskBase.h"
#include "FStateTreeTask_ShroudKnightWarpStrike.generated.h"

class AAshenShroudKnight;

USTRUCT(BlueprintType)
struct ASHENOATH_API FStateTreeTask_ShroudKnightWarpStrikeInstanceData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Input")
	TWeakObjectPtr<AActor> TargetActor;

	UPROPERTY(EditAnywhere, Category = "Parameter")
	float AttackTimeout = 3.0f;

	UPROPERTY(Transient)
	float ElapsedTime = 0.0f;

	UPROPERTY(Transient)
	bool bStrikeExecuted = false;

	UPROPERTY(Transient)
	TWeakObjectPtr<AAshenShroudKnight> CachedKnight;
};

/**
 * FStateTreeTask_ShroudKnightWarpStrike
 *
 * StateTree task governing the Shroud-Knight's high-speed Warp-Strike teleportation assault.
 * Applies Creeping Paranoia infection on target impact.
 */
USTRUCT(BlueprintType, meta = (DisplayName = "Ashen Shroud Knight Warp Strike"))
struct ASHENOATH_API FStateTreeTask_ShroudKnightWarpStrike final : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

	typedef FStateTreeTask_ShroudKnightWarpStrikeInstanceData FInstanceDataType;

	virtual const UScriptStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }

	virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const override;
	virtual EStateTreeRunStatus Tick(FStateTreeExecutionContext& Context, const float DeltaTime) const override;
	virtual void ExitState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const override;
};
