// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenWorldBossPhaseControllerComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnWorldBossPhaseTransitionedSignature, int32, NewPhaseIndex, float, PhaseEnrageMultiplier);

/**
 * UAshenWorldBossPhaseControllerComponent
 *
 * Component managing dynamic multi-phase boss transitions.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenWorldBossPhaseControllerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenWorldBossPhaseControllerComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|BossPhase")
	void AdvanceBossPhase(int32 NextPhaseIndex, float EnrageMultiplier = 1.25f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|BossPhase|Events")
	FOnWorldBossPhaseTransitionedSignature OnBossPhaseTransitioned;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|BossPhase")
	int32 CurrentPhaseIndex = 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|BossPhase")
	float ActiveEnrageMultiplier = 1.0f;
};
