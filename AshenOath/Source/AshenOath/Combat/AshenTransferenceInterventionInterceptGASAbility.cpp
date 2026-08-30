// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenTransferenceInterventionInterceptGASAbility.h"
#include "Soul/AshenSoulPublisher.h"
#include "Soul/AshenSoulStateVector.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"

UAshenTransferenceInterventionInterceptGASAbility::UAshenTransferenceInterventionInterceptGASAbility()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	NetExecutionPolicy = EGameplayAbilityNetExecutionPolicy::LocalPredicted;
	TrustRewardScalar = 0.20f;
}

void UAshenTransferenceInterventionInterceptGASAbility::ActivateAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	if (UAshenSoulPublisher* Publisher = GetSoulPublisher())
	{
		FSoulStateVector Delta;
		Delta.Resolve = 0.10f;
		Delta.Corruption = 0.0f;
		Delta.IntegrationDebt = 0.10f; // Interception incurs strain
		Delta.Isolation = -0.15f; // Deepens relational connection
		Delta.GarrettTrust = TrustRewardScalar;
		Delta.SerafinaTrust = TrustRewardScalar;
		Publisher->CommitState(Delta);
	}

	UE_LOG(LogTemp, Warning, TEXT("UAshenTransferenceInterventionInterceptGASAbility: INTERVENTION EXECUTED (+%.2f Trust committed to SSoT)!"),
		TrustRewardScalar);

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}

void UAshenTransferenceInterventionInterceptGASAbility::EndAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	bool bReplicateEndAbility,
	bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}

UAshenSoulPublisher* UAshenTransferenceInterventionInterceptGASAbility::GetSoulPublisher() const
{
	if (const UWorld* World = GetWorld())
	{
		if (const UGameInstance* GI = World->GetGameInstance())
		{
			return GI->GetSubsystem<UAshenSoulPublisher>();
		}
	}
	return nullptr;
}
