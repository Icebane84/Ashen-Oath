// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Audio/AshenQuartzAudioTypes.h"
#include "Audio/AshenQuartzMusicConductorSubsystem.h"
#include "Audio/AshenStemGainMatrixEvaluator.h"
#include "Audio/AshenAlchemicalAudioFilterEvaluator.h"
#include "Audio/AshenSymbioticFlowDirectorComponent.h"
#include "Audio/AshenQuartzHapticBridge.h"
#include "Core/AshenQuartzAudioSaveGameAdapter.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch143AutomationTest,
	"AshenOath.Audio.MasterBatch143_QuartzDynamic6StemConductorSymbioticFlow",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMasterBatch143AutomationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. TEST 6-STEM GAIN MATRIX EVALUATION
	// -----------------------------------------------------------------------------------
	{
		UAshenStemGainMatrixEvaluator* GainEvaluator = NewObject<UAshenStemGainMatrixEvaluator>();

		// Baseline: Stem 01 = 0.10, Stem 02 = 0.00, Stem 03 = 0.80, Stem 05 = 1.00
		const float BaselineS1 = GainEvaluator->EvaluateStemGain(EQuartzAudioStem::Stem01_IndustrialDrums, 0.0f, 0.0f, ECombatFlowState::StandardTrioBaseline);
		const float BaselineS2 = GainEvaluator->EvaluateStemGain(EQuartzAudioStem::Stem02_NightsteelHum, 0.0f, 0.0f, ECombatFlowState::StandardTrioBaseline);
		const float BaselineS3 = GainEvaluator->EvaluateStemGain(EQuartzAudioStem::Stem03_SoloViolin, 0.0f, 0.0f, ECombatFlowState::StandardTrioBaseline);
		const float BaselineS5 = GainEvaluator->EvaluateStemGain(EQuartzAudioStem::Stem05_PaladinChoir, 0.0f, 0.0f, ECombatFlowState::StandardTrioBaseline);

		TestNearlyEqual(TEXT("Baseline Stem 01 is 0.10"), BaselineS1, 0.10f, 0.01f);
		TestNearlyEqual(TEXT("Baseline Stem 02 is 0.00"), BaselineS2, 0.00f, 0.01f);
		TestNearlyEqual(TEXT("Baseline Stem 03 is 0.80"), BaselineS3, 0.80f, 0.01f);
		TestNearlyEqual(TEXT("Baseline Stem 05 is 1.00"), BaselineS5, 1.00f, 0.01f);

		// Symbiotic Flow State: Stem 02 must be 0.00 (Muted!), Stem 03 & 04 & 06 = 1.00
		const float FlowS2 = GainEvaluator->EvaluateStemGain(EQuartzAudioStem::Stem02_NightsteelHum, 0.80f, 0.80f, ECombatFlowState::SymbioticResonance);
		const float FlowS3 = GainEvaluator->EvaluateStemGain(EQuartzAudioStem::Stem03_SoloViolin, 0.80f, 0.80f, ECombatFlowState::SymbioticResonance);
		const float FlowS4 = GainEvaluator->EvaluateStemGain(EQuartzAudioStem::Stem04_ElectricGuitar, 0.80f, 0.80f, ECombatFlowState::SymbioticResonance);
		const float FlowS6 = GainEvaluator->EvaluateStemGain(EQuartzAudioStem::Stem06_AfroPopGroove, 0.80f, 0.80f, ECombatFlowState::SymbioticResonance);

		TestNearlyEqual(TEXT("Flow State Stem 02 is SILENCED (0.00)"), FlowS2, 0.00f, 0.01f);
		TestNearlyEqual(TEXT("Flow State Stem 03 is 1.00"), FlowS3, 1.00f, 0.01f);
		TestNearlyEqual(TEXT("Flow State Stem 04 is 1.00"), FlowS4, 1.00f, 0.01f);
		TestNearlyEqual(TEXT("Flow State Stem 06 is 1.00"), FlowS6, 1.00f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 2. TEST ALCHEMICAL AUDIO FILTERS
	// -----------------------------------------------------------------------------------
	{
		UAshenAlchemicalAudioFilterEvaluator* FilterEvaluator = NewObject<UAshenAlchemicalAudioFilterEvaluator>();

		// Smoke Balm LPF cutoff -> 450 Hz
		const float SmokeLPF = FilterEvaluator->EvaluateLPFCutoffHz(EAlchemicalAudioFilter::SmokeLowPass450Hz);
		TestNearlyEqual(TEXT("Smoke Balm LPF is 450Hz"), SmokeLPF, 450.0f, 0.01f);

		// Sentinel Tackle Side-Chain -> -24 dB
		const float TackleDuck = FilterEvaluator->EvaluateSideChainDuckingDB(EAlchemicalAudioFilter::TackleSideChain);
		TestNearlyEqual(TEXT("Sentinel Tackle side-chain is -24dB"), TackleDuck, -24.0f, 0.01f);

		// Gloomwood Chill Pitch -> -12 Semitones
		const float PitchOffset = FilterEvaluator->EvaluatePitchOffsetSemitones(EAlchemicalAudioFilter::GloomwoodChill);
		TestNearlyEqual(TEXT("Gloomwood Chill pitch offset is -12 ST"), PitchOffset, -12.0f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST SYMBIOTIC FLOW STATE RECOVERY & BUFFS
	// -----------------------------------------------------------------------------------
	{
		UAshenSymbioticFlowDirectorComponent* FlowDirector = NewObject<UAshenSymbioticFlowDirectorComponent>();

		// Baseline vs Flow stamina regen
		TestNearlyEqual(TEXT("Baseline stamina regen is 1.0x"), FlowDirector->EvaluateStaminaRegenMultiplier(ECombatFlowState::StandardTrioBaseline), 1.0f, 0.01f);
		TestNearlyEqual(TEXT("Flow stamina regen is 2.0x"), FlowDirector->EvaluateStaminaRegenMultiplier(ECombatFlowState::SymbioticResonance), 2.0f, 0.01f);

		// Flow damage bonus
		TestNearlyEqual(TEXT("Flow damage bonus is +30%"), FlowDirector->EvaluateFlowDamageBonus(ECombatFlowState::SymbioticResonance), 0.30f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST DUALSENSE HAPTICS
	// -----------------------------------------------------------------------------------
	{
		UAshenQuartzHapticBridge* HapticBridge = NewObject<UAshenQuartzHapticBridge>();
		float RhythmPulse = 0.0f;
		float TackleRumble = 0.0f;
		float FlowVibe = 0.0f;

		// Tackle impact haptics
		HapticBridge->EvaluateQuartzHaptics(ECombatFlowState::CrisisNearBreakdown, EAlchemicalAudioFilter::TackleSideChain, RhythmPulse, TackleRumble, FlowVibe);
		TestNearlyEqual(TEXT("Tackle impact rumble is 0.95"), TackleRumble, 0.95f, 0.01f);

		// Flow state haptics
		HapticBridge->EvaluateQuartzHaptics(ECombatFlowState::SymbioticResonance, EAlchemicalAudioFilter::None, RhythmPulse, TackleRumble, FlowVibe);
		TestNearlyEqual(TEXT("Flow state rhythm pulse is 0.85"), RhythmPulse, 0.85f, 0.01f);
		TestNearlyEqual(TEXT("Flow state harmonic vibe is 0.60"), FlowVibe, 0.60f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 5. TEST SAVEGAME PERSISTENCE
	// -----------------------------------------------------------------------------------
	{
		UAshenQuartzAudioSaveGameAdapter* SaveAdapter = NewObject<UAshenQuartzAudioSaveGameAdapter>();
		SaveAdapter->PackageAudioPreferences(115.0f, true, 7);
		TestTrue(TEXT("SaveData is true"), SaveAdapter->HasSavedData());

		float RestoredBPM = 0.0f;
		bool bRestoredVocals = false;
		int32 RestoredFlows = 0;

		const bool bSuccess = SaveAdapter->RestoreAudioPreferences(RestoredBPM, bRestoredVocals, RestoredFlows);
		TestTrue(TEXT("Restore succeeded"), bSuccess);
		TestNearlyEqual(TEXT("Restored BPM is 115"), RestoredBPM, 115.0f, 0.01f);
		TestTrue(TEXT("Restored vocals is true"), bRestoredVocals);
		TestEqual(TEXT("Restored total flows is 7"), RestoredFlows, 7);
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
