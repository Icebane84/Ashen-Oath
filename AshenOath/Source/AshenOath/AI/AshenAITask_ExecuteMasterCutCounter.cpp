// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AI/AshenAITask_ExecuteMasterCutCounter.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemGlobals.h"
#include "Combat/AshenGameplayAbility_CombatStrike.h"

UAshenAITask_ExecuteMasterCutCounter::UAshenAITask_ExecuteMasterCutCounter()
{
	PrimaryComponentTick.bCanEverTick = false;
}

bool UAshenAITask_ExecuteMasterCutCounter::ExecuteCounterStrike(const FLiechtenauerCounterRule& CounterRule)
{
	AActor* OwnerActor = GetOwner();
	if (!OwnerActor)
	{
		return false;
	}

	UAbilitySystemComponent* OwnerASC = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(OwnerActor);
	if (!OwnerASC)
	{
		return false;
	}

	if (!CounterRule.CounterAbilityClass)
	{
		return false;
	}

	// Grant and activate the counter ability if not already granted
	FGameplayAbilitySpec Spec(CounterRule.CounterAbilityClass, 1, INDEX_NONE, OwnerActor);
	FGameplayAbilitySpecHandle Handle = OwnerASC->GiveAbility(Spec);

	bool bActivated = OwnerASC->TryActivateAbility(Handle);
	if (bActivated)
	{
		if (OnMasterCutCounterExecuted.IsBound())
		{
			OnMasterCutCounterExecuted.Broadcast(CounterRule.RecommendedCounterCut);
		}
	}

	return bActivated;
}
