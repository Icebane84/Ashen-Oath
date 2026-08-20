// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "StateTreeTaskBase.h"
#include "FStateTreeTask_AbominationSweep.generated.h"

class AAshenAbomination;

/** Instance data for FStateTreeTask_AbominationSweep */
USTRUCT(BlueprintType)
struct ASHENOATH_API FStateTreeTask_AbominationSweepInstanceData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Input")
	TWeakObjectPtr<AActor> TargetActor;

	UPROPERTY(EditAnywhere, Category = "Parameter")
	float WindUpDuration = 0.8f;

	UPROPERTY(EditAnywhere, Category = "Parameter")
	float TotalAttackDuration = 2.2f;

	UPROPERTY(Transient)
	float ElapsedTime = 0.0f;

	UPROPERTY(Transient)
	bool bSweepExecuted = false;

	UPROPERTY(Transient)
	TWeakObjectPtr<AAshenAbomination> CachedBoss;
};

/**
 * FStateTreeTask_AbominationSweep
 *
 * StateTree task governing the Ashen Abomination's 3-limb bone spur sweep arc.
 * Features wide-angle crowd knockback (450uu radius, 60 damage) targeting multiple party members.
 */
USTRUCT(BlueprintType, meta = (DisplayName = "Ashen Abomination Bone Spur Sweep"))
struct ASHENOATH_API FStateTreeTask_AbominationSweep final : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

	typedef FStateTreeTask_AbominationSweepInstanceData FInstanceDataType;

	virtual const UScriptStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }

	virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const override;
	virtual EStateTreeRunStatus Tick(FStateTreeExecutionContext& Context, const float DeltaTime) const override;
	virtual void ExitState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const override;
};
