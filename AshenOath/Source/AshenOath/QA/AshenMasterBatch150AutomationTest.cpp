// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Combat/AshenCombatKinematicsTypes.h"
#include "Combat/AshenCombatKinematicsConvergenceSubsystem.h"
#include "Combat/AshenWeightClassDodgeEvaluator.h"
#include "Combat/AshenCardiacExhaustionEvaluator.h"
#include "Combat/AshenPoiseBreakHitstopEvaluator.h"
#include "Combat/AshenCombatKinematicsHapticBridge.h"
#include "Core/AshenCombatKinematicsSaveGameAdapter.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch150AutomationTest,
	"AshenOath.Combat.MasterBatch150_CoreCombatKinematicsConvergence",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMasterBatch150AutomationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. TEST WEIGHT CLASS DODGE SCALING PARAMETERS
	// -----------------------------------------------------------------------------------
	{
		UAshenWeightClassDodgeEvaluator* DodgeEvaluator = NewObject<UAshenWeightClassDodgeEvaluator>();

		// Light Load: 0.32s roll, 0.28s i-frames, 15 stamina, 1650 launch force
		const FDodgeScalingParameters LightParams = DodgeEvaluator->GetDodgeParametersForWeightClass(EAshenWeightClass::LightLoad);
		TestNearlyEqual(TEXT("Light roll duration is 0.32s"), LightParams.RollDurationSeconds, 0.32f, 0.01f);
		TestNearlyEqual(TEXT("Light i-frame duration is 0.28s"), LightParams.IFrameDurationSeconds, 0.28f, 0.01f);
		TestNearlyEqual(TEXT("Light stamina cost is 15.0"), LightParams.StaminaCost, 15.0f, 0.01f);
		TestNearlyEqual(TEXT("Light launch force is 1650.0"), LightParams.LaunchForce, 1650.0f, 0.01f);

		// Heavy Load: 0.55s roll, 0.16s i-frames, 35 stamina, 1100 launch force
		const FDodgeScalingParameters HeavyParams = DodgeEvaluator->GetDodgeParametersForWeightClass(EAshenWeightClass::HeavyLoad);
		TestNearlyEqual(TEXT("Heavy roll duration is 0.55s"), HeavyParams.RollDurationSeconds, 0.55f, 0.01f);
		TestNearlyEqual(TEXT("Heavy i-frame duration is 0.16s"), HeavyParams.IFrameDurationSeconds, 0.16f, 0.01f);
		TestNearlyEqual(TEXT("Heavy stamina cost is 35.0"), HeavyParams.StaminaCost, 35.0f, 0.01f);
		TestNearlyEqual(TEXT("Heavy launch force is 1100.0"), HeavyParams.LaunchForce, 1100.0f, 0.01f);
		TestNearlyEqual(TEXT("Heavy impact trauma is 0.25"), HeavyParams.ImpactCameraTrauma, 0.25f, 0.01f);

		// Weight Class Classification
		TestTrue(TEXT("10kg / 50kg is LightLoad"), DodgeEvaluator->EvaluateWeightClass(10.0f, 50.0f) == EAshenWeightClass::LightLoad);
		TestTrue(TEXT("25kg / 50kg is MediumLoad"), DodgeEvaluator->EvaluateWeightClass(25.0f, 50.0f) == EAshenWeightClass::MediumLoad);
		TestTrue(TEXT("40kg / 50kg is HeavyLoad"), DodgeEvaluator->EvaluateWeightClass(40.0f, 50.0f) == EAshenWeightClass::HeavyLoad);
		TestTrue(TEXT("60kg / 50kg is Overburdened"), DodgeEvaluator->EvaluateWeightClass(60.0f, 50.0f) == EAshenWeightClass::Overburdened);
	}

	// -----------------------------------------------------------------------------------
	// 2. TEST CARDIAC EXHAUSTION COMBAT PENALTIES
	// -----------------------------------------------------------------------------------
	{
		UAshenCardiacExhaustionEvaluator* CardiacEvaluator = NewObject<UAshenCardiacExhaustionEvaluator>();

		// Critical Stamina (20% < 35% threshold)
		TestNearlyEqual(TEXT("Exhausted swing windup speed is 0.75x"), CardiacEvaluator->EvaluateSwingWindupMultiplier(0.20f), 0.75f, 0.01f);
		TestNearlyEqual(TEXT("Exhausted parry recovery is 1.30x"), CardiacEvaluator->EvaluateParryRecoveryMultiplier(0.20f), 1.30f, 0.01f);
		TestTrue(TEXT("Exhausted trigger resistance > 0.50"), CardiacEvaluator->EvaluateTriggerResistance(0.20f) > 0.50f);

		// Normal Stamina (80%)
		TestNearlyEqual(TEXT("Normal swing windup speed is 1.00x"), CardiacEvaluator->EvaluateSwingWindupMultiplier(0.80f), 1.00f, 0.01f);
		TestNearlyEqual(TEXT("Normal parry recovery is 1.00x"), CardiacEvaluator->EvaluateParryRecoveryMultiplier(0.80f), 1.00f, 0.01f);
		TestNearlyEqual(TEXT("Normal trigger resistance is 0.10"), CardiacEvaluator->EvaluateTriggerResistance(0.80f), 0.10f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST POISE BREAK & HITSTOP CONSTANTS
	// -----------------------------------------------------------------------------------
	{
		UAshenPoiseBreakHitstopEvaluator* HitstopEvaluator = NewObject<UAshenPoiseBreakHitstopEvaluator>();

		TestNearlyEqual(TEXT("Hitstop time dilation is 0.02x"), HitstopEvaluator->GetHitstopTimeDilation(), 0.02f, 0.001f);
		TestNearlyEqual(TEXT("Hitstop duration is 0.20s"), HitstopEvaluator->GetHitstopDurationSeconds(), 0.20f, 0.01f);
		TestNearlyEqual(TEXT("Poise break camera trauma is 0.40"), HitstopEvaluator->GetPoiseBreakCameraTrauma(), 0.40f, 0.01f);
		TestNearlyEqual(TEXT("Riposte bonus damage is +25%"), HitstopEvaluator->GetRiposteDamageBonus(), 0.25f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST DUALSENSE KINEMATICS HAPTICS
	// -----------------------------------------------------------------------------------
	{
		UAshenCombatKinematicsHapticBridge* HapticBridge = NewObject<UAshenCombatKinematicsHapticBridge>();
		float TriggerRes = 0.0f;
		float StaggerImpulse = 0.0f;
		float DeflectionClick = 0.0f;

		// PoiseBroken during cardiac exhaustion
		HapticBridge->EvaluateKinematicsHaptics(true, EPoiseStaggerState::PoiseBroken, EParryRiposteQuality::MissedDeflection, TriggerRes, StaggerImpulse, DeflectionClick);
		TestNearlyEqual(TEXT("Cardiac exhausted trigger resistance is 0.85"), TriggerRes, 0.85f, 0.01f);
		TestNearlyEqual(TEXT("Poise break stagger motor impulse is 0.95"), StaggerImpulse, 0.95f, 0.01f);

		// Perfect riposte with full stamina
		HapticBridge->EvaluateKinematicsHaptics(false, EPoiseStaggerState::SolidGuard, EParryRiposteQuality::PerfectRiposte, TriggerRes, StaggerImpulse, DeflectionClick);
		TestNearlyEqual(TEXT("Normal trigger resistance is 0.10"), TriggerRes, 0.10f, 0.01f);
		TestNearlyEqual(TEXT("Perfect deflection click gain is 0.80"), DeflectionClick, 0.80f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 5. TEST SAVEGAME PERSISTENCE
	// -----------------------------------------------------------------------------------
	{
		UAshenCombatKinematicsSaveGameAdapter* SaveAdapter = NewObject<UAshenCombatKinematicsSaveGameAdapter>();
		SaveAdapter->PackageKinematicsState(38.5f, 50.0f, EAshenWeightClass::HeavyLoad);
		TestTrue(TEXT("SaveData is true"), SaveAdapter->HasSavedData());

		float RestoredWeight = 0.0f;
		float RestoredMaxLoad = 0.0f;
		EAshenWeightClass RestoredClass = EAshenWeightClass::LightLoad;

		const bool bSuccess = SaveAdapter->RestoreKinematicsState(RestoredWeight, RestoredMaxLoad, RestoredClass);
		TestTrue(TEXT("Restore succeeded"), bSuccess);
		TestNearlyEqual(TEXT("Restored weight is 38.5kg"), RestoredWeight, 38.5f, 0.01f);
		TestNearlyEqual(TEXT("Restored max load is 50.0kg"), RestoredMaxLoad, 50.0f, 0.01f);
		TestTrue(TEXT("Restored weight class is HeavyLoad"), RestoredClass == EAshenWeightClass::HeavyLoad);
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
