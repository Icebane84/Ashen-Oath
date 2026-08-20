// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "StateTreeTaskBase.h"
#include "GameplayTagContainer.h"
#include "GameplayAbilitySpecHandle.h"
#include "FStateTreeTask_ExecuteAbility.generated.h"

class UAICognitiveComponent;

USTRUCT(BlueprintType)
struct ASHENOATH_API FStateTreeTask_ExecuteAbilityInstanceData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Input")
	FGameplayTag AbilityTag = FGameplayTag();

	UPROPERTY(Transient)
	FGameplayAbilitySpecHandle ActiveAbilityHandle;

	FDelegateHandle AbilityEndedDelegateHandle;

	UPROPERTY(Transient)
	TWeakObjectPtr<UAICognitiveComponent> CachedCognitiveComp;
};

/**
 * @struct FStateTreeTask_ExecuteAbility
 * Triggers a GAS ability and awaits lifecycle completion via UAICognitiveComponent tokens.
 */
USTRUCT(BlueprintType, meta = (DisplayName = "Ashen Execute GAS Ability"))
struct ASHENOATH_API FStateTreeTask_ExecuteAbility final : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

	typedef FStateTreeTask_ExecuteAbilityInstanceData FInstanceDataType;

	virtual const UScriptStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }

	virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const override;
	virtual EStateTreeRunStatus Tick(FStateTreeExecutionContext& Context, const float DeltaTime) const override;
	virtual void ExitState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const override;
};
