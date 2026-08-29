// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Engine/World.h"
#include "Audio/AshenStemGainMatrixEvaluator.h"
#include "Audio/AshenAlchemicalAudioFilterEvaluator.h"
#include "Audio/AshenQuartzAudioBalanceDataAsset.h"
#include "Audio/AshenQuartzAudioTypes.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenQuartzAudioConvergenceIntegrationTest,
	"AshenOath.Convergence.QuartzAudio.StemsAndAlchemicalFilters",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenQuartzAudioConvergenceIntegrationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. SETUP TRANSIENT WORLD & EVALUATORS
	// -----------------------------------------------------------------------------------
	UWorld* World = UWorld::CreateWorld(EWorldType::Game, false, TEXT("QuartzAudioTestWorld"));
	TestNotNull(TEXT("Transient World created"), World);
	if (!World)
	{
		return false;
	}

	UAshenStemGainMatrixEvaluator* StemEvaluator = NewObject<UAshenStemGainMatrixEvaluator>(World);
	UAshenAlchemicalAudioFilterEvaluator* FilterEvaluator = NewObject<UAshenAlchemicalAudioFilterEvaluator>(World);

	TestNotNull(TEXT("StemEvaluator instantiated"), StemEvaluator);
	TestNotNull(TEXT("FilterEvaluator instantiated"), FilterEvaluator);

	// -----------------------------------------------------------------------------------
	// 2. TEST BASELINE 6-STEM GAINS (C = 0.0, B = 0.0)
	// -----------------------------------------------------------------------------------
	if (StemEvaluator)
	{
		const float G1 = StemEvaluator->EvaluateStemGain(EQuartzAudioStem::Stem01_IndustrialDrums, 0.0f, 0.0f, ECombatFlowState::StandardTrioBaseline);
		const float G2 = StemEvaluator->EvaluateStemGain(EQuartzAudioStem::Stem02_NightsteelHum, 0.0f, 0.0f, ECombatFlowState::StandardTrioBaseline);
		const float G3 = StemEvaluator->EvaluateStemGain(EQuartzAudioStem::Stem03_SoloViolin, 0.0f, 0.0f, ECombatFlowState::StandardTrioBaseline);
		const float G4 = StemEvaluator->EvaluateStemGain(EQuartzAudioStem::Stem04_ElectricGuitar, 0.0f, 0.0f, ECombatFlowState::StandardTrioBaseline);
		const float G5 = StemEvaluator->EvaluateStemGain(EQuartzAudioStem::Stem05_PaladinChoir, 0.0f, 0.0f, ECombatFlowState::StandardTrioBaseline);
		const float G6 = StemEvaluator->EvaluateStemGain(EQuartzAudioStem::Stem06_AfroPopGroove, 0.0f, 0.0f, ECombatFlowState::StandardTrioBaseline);

		TestNearlyEqual(TEXT("Stem 01 baseline gain is 0.10"), G1, 0.10f, 0.01f);
		TestNearlyEqual(TEXT("Stem 02 baseline gain is 0.00"), G2, 0.00f, 0.01f);
		TestNearlyEqual(TEXT("Stem 03 baseline gain is 0.80"), G3, 0.80f, 0.01f);
		TestNearlyEqual(TEXT("Stem 04 baseline gain is 0.00"), G4, 0.00f, 0.01f);
		TestNearlyEqual(TEXT("Stem 05 baseline gain is 1.00"), G5, 1.00f, 0.01f);
		TestNearlyEqual(TEXT("Stem 06 baseline gain is 0.80"), G6, 0.80f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST SYMBIOTIC RESONANCE FLOW STATE PACK CONVERGENCE (STEM 02 SILENCED)
	// -----------------------------------------------------------------------------------
	if (StemEvaluator)
	{
		const float FlowG1 = StemEvaluator->EvaluateStemGain(EQuartzAudioStem::Stem01_IndustrialDrums, 0.9f, 0.5f, ECombatFlowState::SymbioticResonance);
		const float FlowG2 = StemEvaluator->EvaluateStemGain(EQuartzAudioStem::Stem02_NightsteelHum, 0.9f, 0.5f, ECombatFlowState::SymbioticResonance);
		const float FlowG3 = StemEvaluator->EvaluateStemGain(EQuartzAudioStem::Stem03_SoloViolin, 0.9f, 0.5f, ECombatFlowState::SymbioticResonance);
		const float FlowG4 = StemEvaluator->EvaluateStemGain(EQuartzAudioStem::Stem04_ElectricGuitar, 0.9f, 0.5f, ECombatFlowState::SymbioticResonance);
		const float FlowG5 = StemEvaluator->EvaluateStemGain(EQuartzAudioStem::Stem05_PaladinChoir, 0.9f, 0.5f, ECombatFlowState::SymbioticResonance);
		const float FlowG6 = StemEvaluator->EvaluateStemGain(EQuartzAudioStem::Stem06_AfroPopGroove, 0.9f, 0.5f, ECombatFlowState::SymbioticResonance);

		TestNearlyEqual(TEXT("Flow Stem 01 gain is 0.05"), FlowG1, 0.05f, 0.01f);
		TestNearlyEqual(TEXT("Flow Stem 02 is completely silenced (0.00)"), FlowG2, 0.00f, 0.01f);
		TestNearlyEqual(TEXT("Flow Stem 03 solo violin is 1.00"), FlowG3, 1.00f, 0.01f);
		TestNearlyEqual(TEXT("Flow Stem 04 electric guitar is 1.00"), FlowG4, 1.00f, 0.01f);
		TestNearlyEqual(TEXT("Flow Stem 05 paladin choir is 0.00"), FlowG5, 0.00f, 0.01f);
		TestNearlyEqual(TEXT("Flow Stem 06 pack groove is 1.00"), FlowG6, 1.00f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST GARRETT'S ALCHEMICAL DYNAMIC AUDIO FILTERS
	// -----------------------------------------------------------------------------------
	if (FilterEvaluator)
	{
		const float SmokeLPF = FilterEvaluator->EvaluateLPFCutoffHz(EAlchemicalAudioFilter::SmokeLowPass450Hz);
		const float TackleDucking = FilterEvaluator->EvaluateSideChainDuckingDB(EAlchemicalAudioFilter::TackleSideChain);
		const float GloomwoodPitch = FilterEvaluator->EvaluatePitchOffsetSemitones(EAlchemicalAudioFilter::GloomwoodChill);

		TestNearlyEqual(TEXT("Smoke Balm LPF cutoff is 450.0 Hz"), SmokeLPF, 450.0f, 0.1f);
		TestNearlyEqual(TEXT("Sentinel Tackle side-chain ducking is -24.0 dB"), TackleDucking, -24.0f, 0.1f);
		TestNearlyEqual(TEXT("Gloomwood Sap pitch offset is -12.0 ST"), GloomwoodPitch, -12.0f, 0.1f);
	}

	// -----------------------------------------------------------------------------------
	// 5. TEST DATA ASSET LIVE OVERRIDE
	// -----------------------------------------------------------------------------------
	if (FilterEvaluator)
	{
		UAshenQuartzAudioBalanceDataAsset* BalanceAsset = NewObject<UAshenQuartzAudioBalanceDataAsset>(World);
		BalanceAsset->FilterBalancing.SmokeLowPassCutoffHz = 250.0f;
		BalanceAsset->FilterBalancing.TackleSideChainDuckingDB = -36.0f;
		BalanceAsset->FilterBalancing.GloomwoodPitchOffsetSemitones = -18.0f;

		FilterEvaluator->BalanceDataAsset = BalanceAsset;

		const float CustomSmoke = FilterEvaluator->EvaluateLPFCutoffHz(EAlchemicalAudioFilter::SmokeLowPass450Hz);
		const float CustomTackle = FilterEvaluator->EvaluateSideChainDuckingDB(EAlchemicalAudioFilter::TackleSideChain);
		const float CustomPitch = FilterEvaluator->EvaluatePitchOffsetSemitones(EAlchemicalAudioFilter::GloomwoodChill);

		TestNearlyEqual(TEXT("DataAsset live override sets Smoke LPF to 250.0 Hz"), CustomSmoke, 250.0f, 0.1f);
		TestNearlyEqual(TEXT("DataAsset live override sets Tackle ducking to -36.0 dB"), CustomTackle, -36.0f, 0.1f);
		TestNearlyEqual(TEXT("DataAsset live override sets Gloomwood pitch to -18.0 ST"), CustomPitch, -18.0f, 0.1f);
	}

	// Cleanup
	World->DestroyWorld(false);
	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
