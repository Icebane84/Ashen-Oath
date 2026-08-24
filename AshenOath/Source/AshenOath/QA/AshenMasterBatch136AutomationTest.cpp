// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "World/AshenChaosNavmeshTypes.h"
#include "World/AshenChaosNavmeshSubsystem.h"
#include "World/AshenChaosDebrisObstructionEvaluator.h"
#include "World/AshenChaosSpatialAudioEvaluator.h"
#include "Scenarios/AshenChaosNavmeshHapticBridge.h"
#include "Core/AshenChaosNavmeshSaveGameAdapter.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch136AutomationTest,
	"AshenOath.Chaos.MasterBatch136_ChaosNavmeshDestruction",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMasterBatch136AutomationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. TEST DEBRIS OBSTRUCTION & BLOCKING RADIUS MATH
	// -----------------------------------------------------------------------------------
	{
		UAshenChaosDebrisObstructionEvaluator* DebrisEvaluator = NewObject<UAshenChaosDebrisObstructionEvaluator>();

		// 0kg debris -> 150uu base radius
		TestNearlyEqual(TEXT("0kg debris radius is 150uu"), DebrisEvaluator->EvaluateNavmeshBlockingRadius(0.0f), 150.0f, 1.0f);

		// 100kg debris -> 150 + 250 = 400uu radius
		TestNearlyEqual(TEXT("100kg debris radius is 400uu"), DebrisEvaluator->EvaluateNavmeshBlockingRadius(100.0f), 400.0f, 1.0f);

		// Height classification
		TestTrue(TEXT("50uu height is VaultableLowDebris"), DebrisEvaluator->ClassifyObstructionState(50.0f) == ENavmeshObstructionState::VaultableLowDebris);
		TestTrue(TEXT("200uu height is BlockedHighRubble"), DebrisEvaluator->ClassifyObstructionState(200.0f) == ENavmeshObstructionState::BlockedHighRubble);
	}

	// -----------------------------------------------------------------------------------
	// 2. TEST ACOUSTIC IMPACT FREQUENCY & OCCLUSION
	// -----------------------------------------------------------------------------------
	{
		UAshenChaosSpatialAudioEvaluator* AudioEvaluator = NewObject<UAshenChaosSpatialAudioEvaluator>();

		// Granite impact 5000 Joules -> 450 - (5000/50) = 350 Hz
		const float GraniteFreq = AudioEvaluator->EvaluateImpactResonanceFrequency(EStructuralMaterialType::GraniteStone, 5000.0f);
		TestNearlyEqual(TEXT("Granite 5000J impact frequency is 350 Hz"), GraniteFreq, 350.0f, 1.0f);

		// Rubble occlusion for 133kg -> ~50% sound occlusion
		const float Occlusion = AudioEvaluator->EvaluateRubbleSoundOcclusion(133.3f);
		TestNearlyEqual(TEXT("133kg debris occlusion is 0.50"), Occlusion, 0.50f, 0.02f);
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST DUALSENSE COLLAPSE HAPTICS
	// -----------------------------------------------------------------------------------
	{
		UAshenChaosNavmeshHapticBridge* HapticBridge = NewObject<UAshenChaosNavmeshHapticBridge>();
		float LowRumble = 0.0f;
		float HighCrunch = 0.0f;
		float TriggerResistance = 0.0f;

		// Total Demolition at 300uu distance (Falloff = 1 - 300/1500 = 0.80)
		HapticBridge->EvaluateChaosHaptics(EChaosFractureSeverity::TotalDemolition, 8000.0f, 300.0f, LowRumble, HighCrunch, TriggerResistance);
		TestNearlyEqual(TEXT("Low rumble is strong (0.72)"), LowRumble, 0.72f, 0.02f);
		TestNearlyEqual(TEXT("Rubble trigger resistance is 0.80"), TriggerResistance, 0.80f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST SAVEGAME PERSISTENCE
	// -----------------------------------------------------------------------------------
	{
		UAshenChaosNavmeshSaveGameAdapter* SaveAdapter = NewObject<UAshenChaosNavmeshSaveGameAdapter>();
		SaveAdapter->PackageChaosState(4, 2, 450.0f);
		TestTrue(TEXT("HasSavedData is true"), SaveAdapter->HasSavedData());

		int32 RestoredPillars = 0;
		int32 RestoredCleared = 0;
		float RestoredMass = 0.0f;
		const bool bSuccess = SaveAdapter->RestoreChaosState(RestoredPillars, RestoredCleared, RestoredMass);

		TestTrue(TEXT("Restore succeeded"), bSuccess);
		TestEqual(TEXT("Restored fractured pillars is 4"), RestoredPillars, 4);
		TestEqual(TEXT("Restored cleared debris is 2"), RestoredCleared, 2);
		TestNearlyEqual(TEXT("Restored mass is 450kg"), RestoredMass, 450.0f, 0.1f);
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
