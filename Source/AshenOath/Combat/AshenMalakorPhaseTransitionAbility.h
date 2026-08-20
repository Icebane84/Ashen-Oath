// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenMalakorPhaseTransitionAbility.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMalakorPhaseTransitionExecutedSignature, int32, NewBossPhase, float, BerserkAttackSpeedMultiplier);

/**
 * UAshenMalakorPhaseTransitionAbility
 *
 * Ability executing Malakor's transition into Phase 2 Berserk upon losing 50% HP (Where Light Fades Act 01).
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenMalakorPhaseTransitionAbility : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|MalakorBoss")
	void TriggerPhaseTransition(int32 TargetPhase = 2);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|MalakorBoss|Events")
	FOnMalakorPhaseTransitionExecutedSignature OnPhaseTransitionExecuted;
};
