// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 306: GA_KaelenUnchainedVesselState (UMB-SYS-005)

#include "GA_KaelenUnchainedVesselState.h"
#include "AshenSoulStateVectorComponent.h"
#include "AshenFalseConfidenceDeceptionComponent.h"

UGA_KaelenUnchainedVesselState::UGA_KaelenUnchainedVesselState()
{
	IntegrationDebtSurge = 25.0f;
}

void UGA_KaelenUnchainedVesselState::ActivateAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	if (!CommitAbility(Handle, ActorInfo, ActivationInfo))
	{
		EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
		return;
	}

	AActor* Owner = ActorInfo->OwnerActor.Get();
	if (!Owner)
	{
		EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
		return;
	}

	UAshenSoulStateVectorComponent* SoulComp = Owner->FindComponentByClass<UAshenSoulStateVectorComponent>();
	if (SoulComp)
	{
		SoulComp->AccumulateIntegrationDebt(IntegrationDebtSurge);

		UAshenFalseConfidenceDeceptionComponent* DeceptionComp = Owner->FindComponentByClass<UAshenFalseConfidenceDeceptionComponent>();
		if (DeceptionComp)
		{
			DeceptionComp->EvaluateFalseConfidenceState(SoulComp->GetSoulVector());
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("UGA_KaelenUnchainedVesselState: UNCHAINED VESSEL STATE ENTERED by '%s' (+%.0f Integration Debt)."),
		*Owner->GetName(), IntegrationDebtSurge);

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
