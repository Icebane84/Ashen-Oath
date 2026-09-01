// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AI/AshenAIStateTreeEvaluator_Liechtenauer.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemGlobals.h"
#include "GameFramework/Actor.h"

UAshenAIStateTreeEvaluator_Liechtenauer::UAshenAIStateTreeEvaluator_Liechtenauer()
{
	PrimaryComponentTick.bCanEverTick = false;
}

bool UAshenAIStateTreeEvaluator_Liechtenauer::EvaluateCounterDecision(AActor* TargetActor, FLiechtenauerCounterRule& OutSelectedRule)
{
	if (!TargetActor)
	{
		return false;
	}

	if (!LiechtenauerMatrix)
	{
		LiechtenauerMatrix = NewObject<UAshenLiechtenauerMatrixDataAsset>(this);
	}

	UAbilitySystemComponent* TargetASC = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(TargetActor);
	if (!TargetASC)
	{
		return false;
	}

	// Scan target gameplay tags for active Liechtenauer stances
	static const FGameplayTag StanceTagVomTag = FGameplayTag::RequestGameplayTag(FName("State.Stance.VomTag"));
	static const FGameplayTag StanceTagOchs = FGameplayTag::RequestGameplayTag(FName("State.Stance.Ochs"));
	static const FGameplayTag StanceTagPflug = FGameplayTag::RequestGameplayTag(FName("State.Stance.Pflug"));
	static const FGameplayTag StanceTagAlber = FGameplayTag::RequestGameplayTag(FName("State.Stance.Alber"));
	static const FGameplayTag StanceTagMordhau = FGameplayTag::RequestGameplayTag(FName("State.Stance.Mordhau"));

	FGameplayTag DetectedTag = StanceTagVomTag; // Default to Vom Tag

	if (TargetASC->HasMatchingGameplayTag(StanceTagOchs))
	{
		DetectedTag = StanceTagOchs;
	}
	else if (TargetASC->HasMatchingGameplayTag(StanceTagPflug))
	{
		DetectedTag = StanceTagPflug;
	}
	else if (TargetASC->HasMatchingGameplayTag(StanceTagAlber))
	{
		DetectedTag = StanceTagAlber;
	}
	else if (TargetASC->HasMatchingGameplayTag(StanceTagMordhau))
	{
		DetectedTag = StanceTagMordhau;
	}
	else if (TargetASC->HasMatchingGameplayTag(StanceTagVomTag))
	{
		DetectedTag = StanceTagVomTag;
	}

	if (LiechtenauerMatrix->FindCounterRuleForGuard(DetectedTag, OutSelectedRule))
	{
		CurrentRule = OutSelectedRule;
		if (OnLiechtenauerCounterSelected.IsBound())
		{
			OnLiechtenauerCounterSelected.Broadcast(CurrentRule.RecommendedCounterCut, CurrentRule.PostureDamageMultiplier);
		}
		return true;
	}

	return false;
}
