// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AI/AshenLiechtenauerMatrixDataAsset.h"
#include "AI/AshenAIStateTreeEvaluator_Liechtenauer.h"
#include "AI/AshenAITask_ExecuteMasterCutCounter.h"
#include "Combat/AshenMasterCutTypes.h"
#include "Combat/GA_AshenStrike_MasterCuts.h"

#if WITH_DEV_AUTOMATION_TESTS

// -----------------------------------------------------------------------------
// 1. AUTOMATION TEST: Data Asset Matrix Counter Lookup
// -----------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMartialAIMatrixLookupTest,
	"AshenOath.AI.StateTree.MatrixLookup",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMartialAIMatrixLookupTest::RunTest(const FString& Parameters)
{
	UAshenLiechtenauerMatrixDataAsset* Matrix = NewObject<UAshenLiechtenauerMatrixDataAsset>();
	TestNotNull(TEXT("Liechtenauer matrix instantiated"), Matrix);

	if (Matrix)
	{
		// 1. Vom Tag -> Zornhau (1.75x)
		FLiechtenauerCounterRule RuleVomTag;
		bool bFoundVT = Matrix->FindCounterRuleForGuard(FGameplayTag::RequestGameplayTag(FName("State.Stance.VomTag")), RuleVomTag);
		TestTrue(TEXT("Vom Tag rule found"), bFoundVT);
		TestEqual(TEXT("Vom Tag counter cut is Zornhau"), RuleVomTag.RecommendedCounterCut, EAshenMasterCutType::Zornhau);
		TestEqual(TEXT("Vom Tag posture multiplier is 1.75x"), RuleVomTag.PostureDamageMultiplier, 1.75f);

		// 2. Ochs -> Krumphau (2.0x)
		FLiechtenauerCounterRule RuleOchs;
		bool bFoundOX = Matrix->FindCounterRuleForGuard(FGameplayTag::RequestGameplayTag(FName("State.Stance.Ochs")), RuleOchs);
		TestTrue(TEXT("Ochs rule found"), bFoundOX);
		TestEqual(TEXT("Ochs counter cut is Krumphau"), RuleOchs.RecommendedCounterCut, EAshenMasterCutType::Krumphau);
		TestEqual(TEXT("Ochs posture multiplier is 2.0x (shield breaker)"), RuleOchs.PostureDamageMultiplier, 2.0f);

		// 3. Alber -> Scheitelhau (1.9x)
		FLiechtenauerCounterRule RuleAlber;
		bool bFoundAL = Matrix->FindCounterRuleForGuard(FGameplayTag::RequestGameplayTag(FName("State.Stance.Alber")), RuleAlber);
		TestTrue(TEXT("Alber rule found"), bFoundAL);
		TestEqual(TEXT("Alber counter cut is Scheitelhau"), RuleAlber.RecommendedCounterCut, EAshenMasterCutType::Scheitelhau);
		TestEqual(TEXT("Alber posture multiplier is 1.9x"), RuleAlber.PostureDamageMultiplier, 1.9f);
	}

	return true;
}

// -----------------------------------------------------------------------------
// 2. AUTOMATION TEST: StateTree Evaluator Stance Sensing
// -----------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMartialAIEvaluatorTest,
	"AshenOath.AI.StateTree.StanceEvaluation",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMartialAIEvaluatorTest::RunTest(const FString& Parameters)
{
	UAshenAIStateTreeEvaluator_Liechtenauer* Evaluator = NewObject<UAshenAIStateTreeEvaluator_Liechtenauer>();
	TestNotNull(TEXT("StateTree evaluator instantiated"), Evaluator);

	if (Evaluator)
	{
		Evaluator->LiechtenauerMatrix = NewObject<UAshenLiechtenauerMatrixDataAsset>();
		TestNotNull(TEXT("Matrix data asset assigned"), Evaluator->LiechtenauerMatrix.Get());
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
