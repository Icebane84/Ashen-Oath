// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenBossMultiPhaseTransitionComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnBossPhaseTransitionedSignature, int32, NewPhaseIndex, float, PhaseHealthThreshold);

/**
 * UAshenBossMultiPhaseTransitionComponent
 *
 * Multi-phase boss transition component projecting into 3 distinct layers under Constitutional Law #476:
 * Layer 1 (Combat): Posture break immunity & aggressive attack speed boost.
 * Layer 2 (Audio/VFX): Arena fire decal instantiation & MetaSound phase transition sting.
 * Layer 3 (Dialogue): Companion warning voice bark (e.g., Garrett: "He's entering his second phase!").
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenBossMultiPhaseTransitionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenBossMultiPhaseTransitionComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|BossPhase")
	void EvaluateBossPhaseTransition(float CurrentHealth, float MaxHealth);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|BossPhase|Events")
	FOnBossPhaseTransitionedSignature OnPhaseTransitioned;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|BossPhase")
	int32 CurrentPhaseIndex = 1;
};
