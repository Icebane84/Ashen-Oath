// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AbilityTask_EvaluateMontageFlowPosition.h"
#include "GameFramework/Character.h"
#include "Components/SkeletalMeshComponent.h"
#include "Animation/AnimMontage.h"
#include "Animation/AnimInstance.h"

UAbilityTask_EvaluateMontageFlowPosition::UAbilityTask_EvaluateMontageFlowPosition()
{
	bTickingTask = true;
	bInputEvaluated = false;
	ApexPosition = 0.0f;
	WindowDuration = InvariantWindowDuration;
}

UAbilityTask_EvaluateMontageFlowPosition* UAbilityTask_EvaluateMontageFlowPosition::CreateMontageFlowPositionEvaluator(
	UGameplayAbility* OwningAbility,
	UAnimMontage* TargetMontage,
	float ApexPositionSeconds,
	float WindowDurationSeconds)
{
	UAbilityTask_EvaluateMontageFlowPosition* Task = NewAbilityTask<UAbilityTask_EvaluateMontageFlowPosition>(OwningAbility);
	Task->MonitoredMontage = TargetMontage;
	Task->ApexPosition = ApexPositionSeconds;
	Task->WindowDuration = WindowDurationSeconds;
	return Task;
}

void UAbilityTask_EvaluateMontageFlowPosition::Activate()
{
	Super::Activate();

	const ACharacter* Character = Cast<ACharacter>(GetAvatarActor());
	if (Character && Character->GetMesh())
	{
		CachedAnimInstance = Character->GetMesh()->GetAnimInstance();
	}

	if (!CachedAnimInstance || !MonitoredMontage)
	{
		EndTask();
	}
}

void UAbilityTask_EvaluateMontageFlowPosition::TickTask(float DeltaTime)
{
	Super::TickTask(DeltaTime);

	if (!CachedAnimInstance || !MonitoredMontage)
	{
		EndTask();
		return;
	}

	const float CurrentPosition = CachedAnimInstance->Montage_GetPosition(MonitoredMontage);
	const float WindowEnd = ApexPosition + WindowDuration;

	// If position passed window without input, flag as Missed
	if (!bInputEvaluated && CurrentPosition > WindowEnd)
	{
		bInputEvaluated = true;
		OnInputResolved.Broadcast(EAshenFlowTimingResult::Missed);
		EndTask();
	}
}

EAshenFlowTimingResult UAbilityTask_EvaluateMontageFlowPosition::RegisterInputAttempt()
{
	if (bInputEvaluated || !CachedAnimInstance || !MonitoredMontage)
	{
		return EAshenFlowTimingResult::Missed;
	}

	bInputEvaluated = true;
	const float CurrentPosition = CachedAnimInstance->Montage_GetPosition(MonitoredMontage);
	const EAshenFlowTimingResult Result = EvaluateFlowTiming(CurrentPosition, ApexPosition, WindowDuration);

	OnInputResolved.Broadcast(Result);
	EndTask();
	return Result;
}

EAshenFlowTimingResult UAbilityTask_EvaluateMontageFlowPosition::EvaluateFlowTiming(
	float CurrentMontagePosition,
	float ApexPositionSeconds,
	float WindowDurationSeconds)
{
	const float WindowStart = ApexPositionSeconds;
	const float WindowEnd = ApexPositionSeconds + WindowDurationSeconds;

	if (CurrentMontagePosition < WindowStart)
	{
		return EAshenFlowTimingResult::Early;
	}
	else if (CurrentMontagePosition >= WindowStart && CurrentMontagePosition <= WindowEnd)
	{
		return EAshenFlowTimingResult::Perfect;
	}
	else
	{
		return EAshenFlowTimingResult::Late;
	}
}

void UAbilityTask_EvaluateMontageFlowPosition::OnDestroy(bool bInOwnerFinished)
{
	CachedAnimInstance = nullptr;
	MonitoredMontage = nullptr;
	Super::OnDestroy(bInOwnerFinished);
}
