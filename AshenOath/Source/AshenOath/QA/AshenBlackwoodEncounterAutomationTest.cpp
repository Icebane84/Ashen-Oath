// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 765: Ashen Blackwood Encounter Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenBlackwoodCorruptedMistVolumeComponent.h"
#include "AshenMalakorPhaseTransitionAbility.h"
#include "AshenBlackwoodEncounterRewardCalculator.h"

// =============================================================================
//  Test 1: Blackwood Corrupted Mist Volume Component — Update Mist Density
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenBlackwoodCorruptedMistVolumeComponentTest,
	"AshenOath.CorruptedMist.Component.UpdateDensity",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenBlackwoodCorruptedMistVolumeComponentTest::RunTest(const FString& Parameters)
{
	UAshenBlackwoodCorruptedMistVolumeComponent* MistComp = NewObject<UAshenBlackwoodCorruptedMistVolumeComponent>();
	if (!TestNotNull(TEXT("BlackwoodCorruptedMistVolumeComponent must be constructable"), MistComp)) return false;

	MistComp->UpdateMistDensity(90.0f);
	TestEqual(TEXT("ActiveMistDensity must equal 90.0%"), MistComp->ActiveMistDensity, 90.0f);

	return true;
}

// =============================================================================
//  Test 2: Malakor Phase Transition Ability — Trigger Phase Transition
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMalakorPhaseTransitionAbilityTest,
	"AshenOath.MalakorBoss.Ability.PhaseTransition",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMalakorPhaseTransitionAbilityTest::RunTest(const FString& Parameters)
{
	UAshenMalakorPhaseTransitionAbility* Ability = NewObject<UAshenMalakorPhaseTransitionAbility>();
	if (!TestNotNull(TEXT("MalakorPhaseTransitionAbility must be constructable"), Ability)) return false;

	Ability->TriggerPhaseTransition(2);
	return true;
}

// =============================================================================
//  Test 3: Blackwood Encounter Reward Calculator — Calculate Rewards
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenBlackwoodEncounterRewardCalculatorTest,
	"AshenOath.BlackwoodReward.Calculator.CalculateRewards",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenBlackwoodEncounterRewardCalculatorTest::RunTest(const FString& Parameters)
{
	UAshenBlackwoodEncounterRewardCalculator* Calc = NewObject<UAshenBlackwoodEncounterRewardCalculator>();
	if (!TestNotNull(TEXT("BlackwoodEncounterRewardCalculator must be constructable"), Calc)) return false;

	Calc->CalculateEncounterRewards(120.0f, 80.0f);
	return true;
}
