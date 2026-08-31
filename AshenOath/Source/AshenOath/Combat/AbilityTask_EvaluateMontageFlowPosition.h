// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "AbilityTask_EvaluateMontageFlowPosition.generated.h"

class UAnimMontage;
class UAnimInstance;

UENUM(BlueprintType)
enum class EAshenFlowTimingResult : uint8
{
	Early,
	Perfect,
	Late,
	Missed
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFlowTimingResultDelegate, EAshenFlowTimingResult, Result);

UCLASS()
class ASHENOATH_API UAbilityTask_EvaluateMontageFlowPosition : public UAbilityTask
{
	GENERATED_BODY()

public:
	UAbilityTask_EvaluateMontageFlowPosition();

	/**
	 * Pure mathematical evaluation of Flow timing:
	 * Uses half-open interval [ApexPosition, ApexPosition + WindowDuration) in montage-local seconds.
	 */
	UFUNCTION(BlueprintPure, Category = "Ashen|Combat")
	static EAshenFlowTimingResult EvaluateFlowTiming(float CurrentMontagePosition, float ApexPositionSeconds, float WindowDurationSeconds = 0.15f);

	UFUNCTION(BlueprintCallable, Category = "Ashen|AbilityTasks", meta = (HidePin = "OwningAbility", DefaultToSelf = "OwningAbility", BlueprintInternalUseOnly = "TRUE"))
	static UAbilityTask_EvaluateMontageFlowPosition* CreateMontageFlowPositionEvaluator(
		UGameplayAbility* OwningAbility,
		UAnimMontage* TargetMontage,
		float ApexPositionSeconds,
		float WindowDurationSeconds = 0.15f
	);

	virtual void Activate() override;
	virtual void TickTask(float DeltaTime) override;
	virtual void OnDestroy(bool bInOwnerFinished) override;

	/** Called when player buffers a transition/action */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Combat")
	EAshenFlowTimingResult RegisterInputAttempt();

	UPROPERTY(BlueprintAssignable)
	FFlowTimingResultDelegate OnInputResolved;

protected:
	UPROPERTY()
	TObjectPtr<UAnimMontage> MonitoredMontage;

	UPROPERTY()
	TObjectPtr<UAnimInstance> CachedAnimInstance;

	float ApexPosition;
	float WindowDuration;
	bool bInputEvaluated;
};
