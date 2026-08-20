// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 342: GA_KaelenEldrinsGambitAbility

#include "GA_KaelenEldrinsGambitAbility.h"
#include "AshenSoulStateVectorComponent.h"
#include "AshenOath_HealthComponent.h"

UGA_KaelenEldrinsGambitAbility::UGA_KaelenEldrinsGambitAbility()
{
	IntegrationDebtCost = 40.0f;
}

void UGA_KaelenEldrinsGambitAbility::ActivateAbility(
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

	// Accumulate Integration Debt
	UAshenSoulStateVectorComponent* SoulComp = Owner->FindComponentByClass<UAshenSoulStateVectorComponent>();
	if (SoulComp)
	{
		SoulComp->AccumulateIntegrationDebt(IntegrationDebtCost);
	}

	// Restore Health to 50%
	UAshenOath_HealthComponent* HealthComp = Owner->FindComponentByClass<UAshenOath_HealthComponent>();
	if (HealthComp)
	{
		HealthComp->Heal(150.0f);
	}

	UE_LOG(LogTemp, Warning, TEXT("UGA_KaelenEldrinsGambitAbility: ELDRIN'S GAMBIT ACTIVATED — Reversed fatal damage (+%.0f Integration Debt)."),
		IntegrationDebtCost);

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
