// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Orchestration/AshenMacroSystemicContractTypes.h"
#include "AshenSomaticWillStruggleGASAbility.generated.h"

/**
 * UAshenSomaticWillStruggleGASAbility
 * 
 * Executes the 2.0s kinetic trigger squeeze for Dialogue / Stagger Trials of Will.
 * Captures an immutable FWillTrialSessionSnapshot at activation to prevent desyncs,
 * enforces mechanical trigger resistance, and resolves Triumph vs Interrupted Struggle.
 */
UCLASS()
class ASHENOATH_API UAshenSomaticWillStruggleGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenSomaticWillStruggleGASAbility();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData) override;

	virtual void EndAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		bool bReplicateEndAbility,
		bool bWasCancelled) override;

	/** Called tick by tick or input pulse to accumulate sustained squeeze */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Combat|Will")
	void RegisterSqueezeInputPulse(float DeltaTime, float SqueezePressure);

	/** Resolves the trial early if player releases trigger */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Combat|Will")
	void InterruptedSqueezeRelease();

	/** Gets active session snapshot */
	UFUNCTION(BlueprintPure, Category = "Ashen|Combat|Will")
	const FWillTrialSessionSnapshot& GetSessionSnapshot() const { return ActiveSnapshot; }

	/** Completion ratio in [0.0, 1.0] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Combat|Will")
	float GetCompletionRatio() const;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Will")
	float RequiredHoldDuration = 2.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Will")
	float MinSqueezePressureThreshold = 0.70f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Will")
	EWillContext TrialContext = EWillContext::DialogueGraceSqueeze;

private:
	UPROPERTY()
	FWillTrialSessionSnapshot ActiveSnapshot;

	float AccumulatedHoldTime = 0.0f;
	bool bTrialResolved = false;
};
