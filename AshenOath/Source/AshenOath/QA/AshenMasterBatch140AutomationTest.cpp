// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Scenarios/AshenScenario10Types.h"
#include "Scenarios/AshenScenario10MissionSubsystem.h"
#include "Scenarios/AshenTripartiteApotheosisEvaluator.h"
#include "Scenarios/AshenZenithConsequenceEvaluator.h"
#include "Scenarios/AshenSoulUnificationDirectorComponent.h"
#include "Scenarios/AshenScenario10HapticBridge.h"
#include "Core/AshenScenario10SaveGameAdapter.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch140AutomationTest,
	"AshenOath.Scenarios.MasterBatch140_SovereignConvergenceGrandZenith",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMasterBatch140AutomationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. TEST CONSEQUENCE ENDING EVALUATION
	// -----------------------------------------------------------------------------------
	{
		UAshenZenithConsequenceEvaluator* Evaluator = NewObject<UAshenZenithConsequenceEvaluator>();

		// Radiant Transfiguration (Trust = 0.90, Debt = 0.15)
		const EZenithConsequenceEnding Ending1 = Evaluator->EvaluateConsequenceEnding(0.90f, 0.15f, false);
		TestEqual(TEXT("High trust, low debt yields Radiant Transfiguration"), Ending1, EZenithConsequenceEnding::RadiantTransfiguration);

		// Cauterized Hegemony (Berserk Dominant)
		const EZenithConsequenceEnding Ending2 = Evaluator->EvaluateConsequenceEnding(0.60f, 0.30f, true);
		TestEqual(TEXT("Berserk dominant yields Cauterized Hegemony"), Ending2, EZenithConsequenceEnding::CauterizedHegemony);

		// Bleeding Fracture (Low Trust < 0.40)
		const EZenithConsequenceEnding Ending3 = Evaluator->EvaluateConsequenceEnding(0.30f, 0.50f, false);
		TestEqual(TEXT("Low trust yields Bleeding Fracture"), Ending3, EZenithConsequenceEnding::BleedingFracture);

		// Ashen Eclipse (High Debt >= 0.85)
		const EZenithConsequenceEnding Ending4 = Evaluator->EvaluateConsequenceEnding(0.80f, 0.90f, false);
		TestEqual(TEXT("High debt yields Ashen Eclipse"), Ending4, EZenithConsequenceEnding::AshenEclipse);
	}

	// -----------------------------------------------------------------------------------
	// 2. TEST TRIPARTITE APOTHEOSIS DAMAGE SCALING
	// -----------------------------------------------------------------------------------
	{
		UAshenTripartiteApotheosisEvaluator* ApothEvaluator = NewObject<UAshenTripartiteApotheosisEvaluator>();

		// 0% resonance -> 1.0x damage, 0% mitigation
		TestNearlyEqual(TEXT("0% resonance damage is 1.0x"), ApothEvaluator->EvaluateApotheosisDamageMultiplier(0.0f), 1.0f, 0.01f);
		TestNearlyEqual(TEXT("0% resonance reduction is 0.0"), ApothEvaluator->EvaluateApotheosisDamageReduction(0.0f), 0.0f, 0.01f);

		// 100% resonance -> 4.0x damage, 75% mitigation
		TestNearlyEqual(TEXT("100% resonance damage is 4.0x"), ApothEvaluator->EvaluateApotheosisDamageMultiplier(1.0f), 4.0f, 0.01f);
		TestNearlyEqual(TEXT("100% resonance reduction is 0.75"), ApothEvaluator->EvaluateApotheosisDamageReduction(1.0f), 0.75f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST SOUL UNIFICATION DIRECTOR COMPONENT
	// -----------------------------------------------------------------------------------
	{
		UAshenSoulUnificationDirectorComponent* Director = NewObject<UAshenSoulUnificationDirectorComponent>();
		TestFalse(TEXT("Not ready at start"), Director->IsApotheosisReady());

		Director->AddResonance(0.60f);
		TestNearlyEqual(TEXT("Resonance is 0.60"), Director->GetCurrentResonance01(), 0.60f, 0.01f);

		Director->AddResonance(0.50f);
		TestNearlyEqual(TEXT("Resonance clamped to 1.00"), Director->GetCurrentResonance01(), 1.00f, 0.01f);
		TestTrue(TEXT("Apotheosis is ready at 1.0"), Director->IsApotheosisReady());
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST DUALSENSE APOTHEOSIS HAPTICS
	// -----------------------------------------------------------------------------------
	{
		UAshenScenario10HapticBridge* HapticBridge = NewObject<UAshenScenario10HapticBridge>();
		float TriggerPulse = 0.0f;
		float LeftMotorPurity = 0.0f;
		float RightMotorKinetic = 0.0f;
		FLinearColor LEDColor;

		// 1.0 resonance, 0.90 trust, 0.20 debt -> Gold Transfiguration
		HapticBridge->EvaluateZenithHaptics(1.0f, 0.90f, 0.20f, TriggerPulse, LeftMotorPurity, RightMotorKinetic, LEDColor);
		TestNearlyEqual(TEXT("Trigger pulse is 0.95"), TriggerPulse, 0.95f, 0.02f);
		TestNearlyEqual(TEXT("Left motor purity is 0.765"), LeftMotorPurity, 0.765f, 0.02f);
		TestNearlyEqual(TEXT("Right motor kinetic is 0.17"), RightMotorKinetic, 0.17f, 0.02f);
		TestNearlyEqual(TEXT("LED is Gold Red channel"), LEDColor.R, 1.0f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 5. TEST SAVEGAME PERSISTENCE
	// -----------------------------------------------------------------------------------
	{
		UAshenScenario10SaveGameAdapter* SaveAdapter = NewObject<UAshenScenario10SaveGameAdapter>();
		SaveAdapter->PackageScenario10State(EZenithConsequenceEnding::RadiantTransfiguration, 0.95f, 0.10f, true);
		TestTrue(TEXT("HasSavedData is true"), SaveAdapter->HasSavedData());

		EZenithConsequenceEnding RestoredEnding;
		float RestoredTrust = 0.0f;
		float RestoredDebt = 0.0f;
		bool bRestoredNGPlus = false;

		const bool bSuccess = SaveAdapter->RestoreScenario10State(RestoredEnding, RestoredTrust, RestoredDebt, bRestoredNGPlus);
		TestTrue(TEXT("Restore succeeded"), bSuccess);
		TestEqual(TEXT("Restored ending is Radiant Transfiguration"), RestoredEnding, EZenithConsequenceEnding::RadiantTransfiguration);
		TestNearlyEqual(TEXT("Restored trust is 0.95"), RestoredTrust, 0.95f, 0.01f);
		TestNearlyEqual(TEXT("Restored debt is 0.10"), RestoredDebt, 0.10f, 0.01f);
		TestTrue(TEXT("Restored NG+ is true"), bRestoredNGPlus);
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
