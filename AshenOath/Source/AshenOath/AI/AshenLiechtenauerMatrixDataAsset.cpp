// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AI/AshenLiechtenauerMatrixDataAsset.h"
#include "Combat/GA_AshenStrike_MasterCuts.h"

UAshenLiechtenauerMatrixDataAsset::UAshenLiechtenauerMatrixDataAsset()
{
	// Default canonical rules from SPEC-109 / liechtenauer_matrix.json
	FLiechtenauerCounterRule RuleVomTag;
	RuleVomTag.TargetGuardTag = FGameplayTag::RequestGameplayTag(FName("State.Stance.VomTag"));
	RuleVomTag.RecommendedCounterCut = EAshenMasterCutType::Zornhau;
	RuleVomTag.CounterAbilityClass = UGA_AshenStrike_Zornhau::StaticClass();
	RuleVomTag.PostureDamageMultiplier = 1.75f;
	RuleVomTag.StaggerDurationSeconds = 1.2f;
	CounterRules.Add(RuleVomTag);

	FLiechtenauerCounterRule RuleOchs;
	RuleOchs.TargetGuardTag = FGameplayTag::RequestGameplayTag(FName("State.Stance.Ochs"));
	RuleOchs.RecommendedCounterCut = EAshenMasterCutType::Krumphau;
	RuleOchs.CounterAbilityClass = UGA_AshenStrike_Krumphau::StaticClass();
	RuleOchs.PostureDamageMultiplier = 2.0f;
	RuleOchs.StaggerDurationSeconds = 1.5f;
	CounterRules.Add(RuleOchs);

	FLiechtenauerCounterRule RulePflug;
	RulePflug.TargetGuardTag = FGameplayTag::RequestGameplayTag(FName("State.Stance.Pflug"));
	RulePflug.RecommendedCounterCut = EAshenMasterCutType::Schielhau;
	RulePflug.CounterAbilityClass = UGA_AshenStrike_Schielhau::StaticClass();
	RulePflug.PostureDamageMultiplier = 1.8f;
	RulePflug.StaggerDurationSeconds = 1.3f;
	CounterRules.Add(RulePflug);

	FLiechtenauerCounterRule RuleAlber;
	RuleAlber.TargetGuardTag = FGameplayTag::RequestGameplayTag(FName("State.Stance.Alber"));
	RuleAlber.RecommendedCounterCut = EAshenMasterCutType::Scheitelhau;
	RuleAlber.CounterAbilityClass = UGA_AshenStrike_Scheitelhau::StaticClass();
	RuleAlber.PostureDamageMultiplier = 1.9f;
	RuleAlber.StaggerDurationSeconds = 1.4f;
	CounterRules.Add(RuleAlber);

	FLiechtenauerCounterRule RuleMordhau;
	RuleMordhau.TargetGuardTag = FGameplayTag::RequestGameplayTag(FName("State.Stance.Mordhau"));
	RuleMordhau.RecommendedCounterCut = EAshenMasterCutType::Mordhau;
	RuleMordhau.CounterAbilityClass = UGA_AshenStrike_Mordhau::StaticClass();
	RuleMordhau.PostureDamageMultiplier = 2.0f;
	RuleMordhau.StaggerDurationSeconds = 1.6f;
	CounterRules.Add(RuleMordhau);
}

bool UAshenLiechtenauerMatrixDataAsset::FindCounterRuleForGuard(const FGameplayTag& GuardTag, FLiechtenauerCounterRule& OutRule) const
{
	for (const FLiechtenauerCounterRule& Rule : CounterRules)
	{
		if (GuardTag.MatchesTag(Rule.TargetGuardTag) || Rule.TargetGuardTag.MatchesTag(GuardTag))
		{
			OutRule = Rule;
			return true;
		}
	}
	return false;
}
