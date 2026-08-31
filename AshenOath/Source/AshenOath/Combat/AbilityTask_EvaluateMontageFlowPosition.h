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
	Early   UMETA(DisplayName = "Early (Queued / 100% Stamina)"),
	Perfect UMETA(DisplayName = "Perfect (0-Stamina Cancel / +25% Speed Boost)"),
	Late    UMETA(DisplayName = "Late (Recovery Lockout / -10% Handling Drag)"),
	Missed  UMETA(DisplayName = "Missed (Expired / Full Recovery Drag)")
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFlowTimingResultDelegate, EAshenFlowTimingResult, Result);

/**
 * UAbilityTask_EvaluateMontageFlowPosition
 *
 * Tracks UAnimMontage track traversal position (P_montage) to evaluate Flow Glint timing.
 * 100% immune to Hit-Stop frame freezes (DeltaT_effective = 0) and scaled with MontagePlayRate.
 * (PRS-001-CDTC-001-V2 / CONVERGENCE-SPEC-101)
 */
UCLASS()
class ASHENOATH_API UAbilityTask_EvaluateMontageFlowPosition : public UAbilityTask
{
	GENERATED_BODY()

public:
	UAbilityTask_EvaluateMontageFlowPosition();

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

	/** Called by the Player Input Component when an attack/stance link is queued */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Combat")
	EAshenFlowTimingResult RegisterInputAttempt();

	/**
	 * Pure classification, independent of any live montage.
	 * Montage-local timeline seconds in, timing verdict out.
	 * Framerate/play-rate agnostic by construction.
	 */
	UFUNCTION(BlueprintPure, Category = "Ashen|Combat", meta = (BlueprintThreadSafe))
	static EAshenFlowTimingResult EvaluateFlowTiming(float CurrentMontagePosition, float ApexPositionSeconds, float WindowDurationSeconds = 0.15f);

	UPROPERTY(BlueprintAssignable)
	FFlowTimingResultDelegate OnInputResolved;

	static constexpr float InvariantWindowDuration = 0.15f; // Invariant montage-local timeline seconds

protected:
	UPROPERTY()
	TObjectPtr<UAnimMontage> MonitoredMontage;

	UPROPERTY()
	TObjectPtr<UAnimInstance> CachedAnimInstance;

	float ApexPosition;
	float WindowDuration;
	bool bInputEvaluated;
};
