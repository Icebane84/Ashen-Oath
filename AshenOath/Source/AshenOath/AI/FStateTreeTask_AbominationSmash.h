// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "StateTreeTaskBase.h"
#include "FStateTreeTask_AbominationSmash.generated.h"

class AAshenAbomination;

/** Instance data for FStateTreeTask_AbominationSmash */
USTRUCT(BlueprintType)
struct ASHENOATH_API FStateTreeTask_AbominationSmashInstanceData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Input")
	TWeakObjectPtr<AActor> TargetActor;

	UPROPERTY(EditAnywhere, Category = "Parameter")
	float WindUpDuration = 1.2f;

	UPROPERTY(EditAnywhere, Category = "Parameter")
	float TotalAttackDuration = 2.8f;

	UPROPERTY(Transient)
	float ElapsedTime = 0.0f;

	UPROPERTY(Transient)
	bool bSmashExecuted = false;

	UPROPERTY(Transient)
	TWeakObjectPtr<AAshenAbomination> CachedBoss;
};

/**
 * FStateTreeTask_AbominationSmash
 *
 * StateTree task governing the Ashen Abomination's massive overhead ground crush attack.
 * Features wind-up telegraphed positioning, ground shatter execution (550uu radius, 80 damage),
 * and post-smash recovery window.
 */
USTRUCT(BlueprintType, meta = (DisplayName = "Ashen Abomination Overhead Smash"))
struct ASHENOATH_API FStateTreeTask_AbominationSmash final : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

	typedef FStateTreeTask_AbominationSmashInstanceData FInstanceDataType;

	virtual const UScriptStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }

	virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const override;
	virtual EStateTreeRunStatus Tick(FStateTreeExecutionContext& Context, const float DeltaTime) const override;
	virtual void ExitState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const override;
};
