// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Engine/World.h"
#include "Narrative/AshenForensicClueRegistryEvaluator.h"
#include "Narrative/AshenMemoryPalaceSynthesisEvaluator.h"
#include "Narrative/AshenForensicMindscapeBalanceDataAsset.h"
#include "Narrative/AshenForensicMindscapeTypes.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenForensicMindscapeConvergenceIntegrationTest,
	"AshenOath.Convergence.Forensic.DeductionAndMemorySynthesis",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenForensicMindscapeConvergenceIntegrationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. SETUP TRANSIENT WORLD & EVALUATORS
	// -----------------------------------------------------------------------------------
	UWorld* World = UWorld::CreateWorld(EWorldType::Game, false, TEXT("ForensicTestWorld"));
	TestNotNull(TEXT("Transient World created"), World);
	if (!World)
	{
		return false;
	}

	UAshenForensicClueRegistryEvaluator* ClueEvaluator = NewObject<UAshenForensicClueRegistryEvaluator>(World);
	UAshenMemoryPalaceSynthesisEvaluator* SynthesisEvaluator = NewObject<UAshenMemoryPalaceSynthesisEvaluator>(World);

	TestNotNull(TEXT("ClueEvaluator instantiated"), ClueEvaluator);
	TestNotNull(TEXT("SynthesisEvaluator instantiated"), SynthesisEvaluator);

	// -----------------------------------------------------------------------------------
	// 2. TEST EVIDENCE CREDIBILITY WEIGHTS
	// -----------------------------------------------------------------------------------
	if (ClueEvaluator)
	{
		const float W_Autopsy = ClueEvaluator->GetCategoryReliabilityWeight(EForensicClueCategory::PhysicalAutopsyEvidence);
		const float W_Chemical = ClueEvaluator->GetCategoryReliabilityWeight(EForensicClueCategory::BotanicalChemicalSample);
		const float W_Runic = ClueEvaluator->GetCategoryReliabilityWeight(EForensicClueCategory::HistoricalRunicInscription);
		const float W_Testimony = ClueEvaluator->GetCategoryReliabilityWeight(EForensicClueCategory::CompanionTestimony);

		TestNearlyEqual(TEXT("Physical autopsy evidence has 1.00 reliability"), W_Autopsy, 1.00f, 0.01f);
		TestNearlyEqual(TEXT("Botanical/Chemical sample has 0.95 reliability"), W_Chemical, 0.95f, 0.01f);
		TestNearlyEqual(TEXT("Historical runic inscription has 0.85 reliability"), W_Runic, 0.85f, 0.01f);
		TestNearlyEqual(TEXT("Companion testimony has 0.65 reliability"), W_Testimony, 0.65f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST SYNTHESIS COHERENCE & MEMORY RESOLVABILITY
	// -----------------------------------------------------------------------------------
	if (SynthesisEvaluator)
	{
		// 3 valid clues with 0.95 average reliability -> ~0.9975 -> Solved!
		const float HighSynthesis = SynthesisEvaluator->EvaluateSynthesisScore(3, 0.95f);
		const bool bHighResolvable = SynthesisEvaluator->IsCaseResolvable(HighSynthesis);
		TestTrue(TEXT("3 valid clues reach high synthesis (>=0.85)"), HighSynthesis >= 0.85f);
		TestTrue(TEXT("Case is resolvable with 3 valid clues"), bHighResolvable);

		// 1 clue with 0.65 reliability -> 0.2275 -> Unsolved
		const float LowSynthesis = SynthesisEvaluator->EvaluateSynthesisScore(1, 0.65f);
		const bool bLowResolvable = SynthesisEvaluator->IsCaseResolvable(LowSynthesis);
		TestTrue(TEXT("1 weak clue yields low synthesis (<0.85)"), LowSynthesis < 0.85f);
		TestFalse(TEXT("Case is NOT resolvable with 1 weak clue"), bLowResolvable);
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST CONTRADICTION DETECTION
	// -----------------------------------------------------------------------------------
	if (SynthesisEvaluator)
	{
		const bool bContradiction = SynthesisEvaluator->DetectContradiction(
			EForensicClueCategory::PhysicalAutopsyEvidence,
			EForensicClueCategory::CompanionTestimony);
		TestTrue(TEXT("Physical autopsy contradicts companion dogma"), bContradiction);

		const bool bNoContradiction = SynthesisEvaluator->DetectContradiction(
			EForensicClueCategory::PhysicalAutopsyEvidence,
			EForensicClueCategory::BotanicalChemicalSample);
		TestFalse(TEXT("Physical autopsy and chemical sample do NOT contradict"), bNoContradiction);
	}

	// -----------------------------------------------------------------------------------
	// 5. TEST DATA ASSET LIVE OVERRIDE
	// -----------------------------------------------------------------------------------
	if (SynthesisEvaluator && ClueEvaluator)
	{
		UAshenForensicMindscapeBalanceDataAsset* BalanceAsset = NewObject<UAshenForensicMindscapeBalanceDataAsset>(World);
		BalanceAsset->DeductionBalancing.ResolutionSynthesisThreshold = 0.50f;
		BalanceAsset->ReliabilityBalancing.AutopsyReliabilityWeight = 0.80f;

		SynthesisEvaluator->BalanceDataAsset = BalanceAsset;
		ClueEvaluator->BalanceDataAsset = BalanceAsset;

		const float CustomWeight = ClueEvaluator->GetCategoryReliabilityWeight(EForensicClueCategory::PhysicalAutopsyEvidence);
		const bool bCustomResolvable = SynthesisEvaluator->IsCaseResolvable(0.55f);

		TestNearlyEqual(TEXT("DataAsset live override sets autopsy reliability to 0.80"), CustomWeight, 0.80f, 0.01f);
		TestTrue(TEXT("DataAsset live override allows resolution at 0.50 threshold"), bCustomResolvable);
	}

	// Cleanup
	World->DestroyWorld(false);
	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
