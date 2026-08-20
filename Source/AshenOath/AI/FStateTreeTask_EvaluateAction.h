// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "StateTreeTaskBase.h"
#include "GameplayTagContainer.h"
#include "FStateTreeTask_EvaluateAction.generated.h"

class UAICognitiveComponent;

USTRUCT(BlueprintType)
struct ASHENOATH_API FStateTreeTask_EvaluateActionInstanceData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Input")
	FGameplayTag ActionTypeTag = FGameplayTag();

	UPROPERTY(EditAnywhere, Category = "Input")
	float BaseUtility = 0.5f;

	UPROPERTY(EditAnywhere, Category = "Input")
	float PreferredRange = 300.0f;

	UPROPERTY(EditAnywhere, Category = "Punish Window")
	FGameplayTag PunishTriggerTag;

	UPROPERTY(EditAnywhere, Category = "Punish Window")
	float PunishRange = 800.0f;

	UPROPERTY(EditAnywhere, Category = "Punish Window")
	float PunishMultiplier = 2.5f;

	UPROPERTY(EditAnywhere, Category = "Entropy")
	float EntropyWindowSeconds = 15.0f;

	UPROPERTY(EditAnywhere, Category = "Entropy")
	float EntropyGamma = 0.4f;

	UPROPERTY(EditAnywhere, Category = "Output")
	float OutCalculatedUtility = 0.0f;

	UPROPERTY(Transient)
	TWeakObjectPtr<UAICognitiveComponent> CachedCognitiveComp;
};

/**
 * @struct FStateTreeTask_EvaluateAction
 * StateTree task executing Markovian utility and input-reading evaluation.
 */
USTRUCT(BlueprintType, meta = (DisplayName = "Ashen Action Evaluation"))
struct ASHENOATH_API FStateTreeTask_EvaluateAction final : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

	typedef FStateTreeTask_EvaluateActionInstanceData FInstanceDataType;

	virtual const UScriptStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }

	virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const override;
	virtual EStateTreeRunStatus Tick(FStateTreeExecutionContext& Context, const float DeltaTime) const override;
};
