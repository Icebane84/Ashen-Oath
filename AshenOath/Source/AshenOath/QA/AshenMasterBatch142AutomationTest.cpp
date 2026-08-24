// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Combat/AshenParasiticBladeTypes.h"
#include "Combat/AshenOathbringerParasiteSubsystem.h"
#include "Combat/AshenParasiticBladeMassEvaluator.h"
#include "Combat/AshenPommelGazeTrackingEvaluator.h"
#include "Combat/AshenGloomwoodStabilizationDirectorComponent.h"
#include "Combat/AshenParasiticBladeHapticBridge.h"
#include "Audio/AshenOathbringerAudioSubsystem.h"
#include "Core/AshenParasiticBladeSaveGameAdapter.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch142AutomationTest,
	"AshenOath.Combat.MasterBatch142_OathbringerParasiticBladeEldrinWhispers",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMasterBatch142AutomationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. TEST PARASITIC BLADE MASS SCALING & PLAY RATE DRAG
	// -----------------------------------------------------------------------------------
	{
		UAshenParasiticBladeMassEvaluator* MassEvaluator = NewObject<UAshenParasiticBladeMassEvaluator>();

		// 0% corruption -> 45kg, 1.00 play rate, 1.0x damage
		const float Mass0 = MassEvaluator->EvaluateBladeMass(0.0f, false);
		TestNearlyEqual(TEXT("0% corruption mass is 45kg"), Mass0, 45.0f, 0.01f);
		TestNearlyEqual(TEXT("45kg swing play rate is 1.00"), MassEvaluator->EvaluateSwingPlayRate(Mass0), 1.0f, 0.01f);
		TestNearlyEqual(TEXT("45kg impact multiplier is 1.0x"), MassEvaluator->EvaluateKineticImpactMultiplier(Mass0), 1.0f, 0.01f);

		// 100% corruption -> 220kg, 0.45 play rate, 2.5x damage
		const float Mass1 = MassEvaluator->EvaluateBladeMass(1.0f, false);
		TestNearlyEqual(TEXT("100% corruption mass is 220kg"), Mass1, 220.0f, 0.01f);
		TestNearlyEqual(TEXT("220kg swing play rate is 0.45"), MassEvaluator->EvaluateSwingPlayRate(Mass1), 0.45f, 0.01f);
		TestNearlyEqual(TEXT("220kg impact multiplier is 2.5x"), MassEvaluator->EvaluateKineticImpactMultiplier(Mass1), 2.5f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 2. TEST GLOOMWOOD SAP NEEDLE STABILIZATION
	// -----------------------------------------------------------------------------------
	{
		UAshenParasiticBladeMassEvaluator* MassEvaluator = NewObject<UAshenParasiticBladeMassEvaluator>();
		UAshenGloomwoodStabilizationDirectorComponent* GloomwoodComp = NewObject<UAshenGloomwoodStabilizationDirectorComponent>();

		// 100% corruption frozen -> 220kg - 80kg = 140kg
		const float FrozenMass = MassEvaluator->EvaluateBladeMass(1.0f, true);
		TestNearlyEqual(TEXT("Frozen 100% mass relieved to 140kg"), FrozenMass, 140.0f, 0.01f);

		// Standard sap pitch drop -> -12 semitones
		const float PitchDrop = GloomwoodComp->EvaluateAudioPitchSemitones(true, EGloomwoodStabilizationTier::StandardSap);
		TestNearlyEqual(TEXT("Standard sap pitch drop is -12 semitones"), PitchDrop, -12.0f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST GARNET POMMEL GAZE & WEEPING BILE
	// -----------------------------------------------------------------------------------
	{
		UAshenPommelGazeTrackingEvaluator* PommelEvaluator = NewObject<UAshenPommelGazeTrackingEvaluator>();

		// Emissive glow at 0% vs 100%
		TestNearlyEqual(TEXT("0% emissive is 0.10"), PommelEvaluator->EvaluatePommelEmissiveGlow(0.0f), 0.10f, 0.01f);
		TestNearlyEqual(TEXT("100% emissive is 1.00"), PommelEvaluator->EvaluatePommelEmissiveGlow(1.0f), 1.00f, 0.01f);

		// Weeping bile check
		TestFalse(TEXT("Not weeping at 0.50 corruption"), PommelEvaluator->IsWeepingBile(0.50f));
		TestTrue(TEXT("Weeping bile at 0.75 corruption"), PommelEvaluator->IsWeepingBile(0.75f));
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST DUALSENSE ADAPTIVE TRIGGER MASS RESISTANCE
	// -----------------------------------------------------------------------------------
	{
		UAshenParasiticBladeHapticBridge* HapticBridge = NewObject<UAshenParasiticBladeHapticBridge>();
		float TriggerRes = 0.0f;
		float Heartbeat = 0.0f;
		float FreezeRumble = 0.0f;

		// 45kg mass -> 0.20 resistance
		HapticBridge->EvaluateBladeHaptics(45.0f, 0.10f, false, TriggerRes, Heartbeat, FreezeRumble);
		TestNearlyEqual(TEXT("45kg trigger resistance is 0.20"), TriggerRes, 0.20f, 0.01f);

		// 220kg mass -> 0.95 resistance
		HapticBridge->EvaluateBladeHaptics(220.0f, 1.0f, false, TriggerRes, Heartbeat, FreezeRumble);
		TestNearlyEqual(TEXT("220kg trigger resistance is 0.95"), TriggerRes, 0.95f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 5. TEST SAVEGAME PERSISTENCE
	// -----------------------------------------------------------------------------------
	{
		UAshenParasiticBladeSaveGameAdapter* SaveAdapter = NewObject<UAshenParasiticBladeSaveGameAdapter>();
		SaveAdapter->PackageBladeState(0.65f, 158.75f, 2, EBladeParasiteState::AwakenedWhispers);
		TestTrue(TEXT("HasSavedData is true"), SaveAdapter->HasSavedData());

		float RestoredCorr = 0.0f;
		float RestoredMass = 0.0f;
		int32 RestoredNeedles = 0;
		EBladeParasiteState RestoredState;

		const bool bSuccess = SaveAdapter->RestoreBladeState(RestoredCorr, RestoredMass, RestoredNeedles, RestoredState);
		TestTrue(TEXT("Restore succeeded"), bSuccess);
		TestNearlyEqual(TEXT("Restored corruption is 0.65"), RestoredCorr, 0.65f, 0.01f);
		TestNearlyEqual(TEXT("Restored mass is 158.75kg"), RestoredMass, 158.75f, 0.01f);
		TestEqual(TEXT("Restored needles count is 2"), RestoredNeedles, 2);
		TestEqual(TEXT("Restored state is AwakenedWhispers"), RestoredState, EBladeParasiteState::AwakenedWhispers);
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
