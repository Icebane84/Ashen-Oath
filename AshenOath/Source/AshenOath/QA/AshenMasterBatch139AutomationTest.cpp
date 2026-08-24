// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Scenarios/AshenScenario9Types.h"
#include "Scenarios/AshenScenario9MissionSubsystem.h"
#include "Scenarios/AshenVoidGravityPhysicsEvaluator.h"
#include "Scenarios/AshenWindShearDriftEvaluator.h"
#include "Scenarios/AshenTelekineticBridgeDirectorComponent.h"
#include "Scenarios/AshenScenario9HapticBridge.h"
#include "Core/AshenScenario9SaveGameAdapter.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch139AutomationTest,
	"AshenOath.Scenarios.MasterBatch139_WhisperingCitadelFloatingArchipelagos",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMasterBatch139AutomationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. TEST VOID GRAVITY PHYSICS EVALUATION
	// -----------------------------------------------------------------------------------
	{
		UAshenVoidGravityPhysicsEvaluator* GravEvaluator = NewObject<UAshenVoidGravityPhysicsEvaluator>();

		// 1.0g -> 1.0x jump
		TestNearlyEqual(TEXT("1.0g jump multiplier is 1.0x"), GravEvaluator->EvaluateJumpDistanceMultiplier(1.0f), 1.0f, 0.01f);

		// 0.1g -> 3.0x jump
		TestNearlyEqual(TEXT("0.1g jump multiplier is 3.0x"), GravEvaluator->EvaluateJumpDistanceMultiplier(0.1f), 3.0f, 0.01f);

		// 0.1g -> 2.5x downward strike multiplier
		TestNearlyEqual(TEXT("0.1g downward strike is 2.5x"), GravEvaluator->EvaluateDownwardStrikeMultiplier(0.1f), 2.5f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 2. TEST WIND SHEAR DRIFT & ANCHOR MECHANICS
	// -----------------------------------------------------------------------------------
	{
		UAshenWindShearDriftEvaluator* WindEvaluator = NewObject<UAshenWindShearDriftEvaluator>();

		// Unanchored 30 m/s wind in X direction -> 900 uu/s drift
		const FVector DriftUnanchored = WindEvaluator->EvaluateAirborneWindDrift(30.0f, FVector(1.0f, 0.0f, 0.0f), false);
		TestNearlyEqual(TEXT("30 m/s unanchored drift is 900 uu/s"), (float)DriftUnanchored.X, 900.0f, 1.0f);

		// Anchored 30 m/s wind -> 0 uu/s drift
		const FVector DriftAnchored = WindEvaluator->EvaluateAirborneWindDrift(30.0f, FVector(1.0f, 0.0f, 0.0f), true);
		TestNearlyEqual(TEXT("30 m/s anchored drift is 0 uu/s"), (float)DriftAnchored.Size(), 0.0f, 0.01f);

		// Destabilization penalty for 45 m/s -> 0.75
		TestNearlyEqual(TEXT("45 m/s wind penalty is 0.75"), WindEvaluator->EvaluateWindDestabilizationPenalty(45.0f, false), 0.75f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST TELEKINETIC BRIDGE DECAY
	// -----------------------------------------------------------------------------------
	{
		UAshenTelekineticBridgeDirectorComponent* BridgeComp = NewObject<UAshenTelekineticBridgeDirectorComponent>();
		BridgeComp->ManifestBridge(10.0f);
		TestTrue(TEXT("Bridge is active after manifestation"), BridgeComp->IsBridgeActive());

		// Decay 5s -> 0.50 stability
		const float Remaining = BridgeComp->DecayBridge(5.0f);
		TestNearlyEqual(TEXT("5s decay leaves 0.50 stability"), Remaining, 0.50f, 0.02f);
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST DUALSENSE HAPTICS
	// -----------------------------------------------------------------------------------
	{
		UAshenScenario9HapticBridge* HapticBridge = NewObject<UAshenScenario9HapticBridge>();
		float TriggerResistance = 0.0f;
		float LeftGripWind = 0.0f;
		float RightGripWind = 0.0f;
		float BridgeHum = 0.0f;

		// 0.35g, 30 m/s wind, 1.0 bridge
		HapticBridge->EvaluateCitadelHaptics(0.35f, 30.0f, 1.0f, TriggerResistance, LeftGripWind, RightGripWind, BridgeHum);
		TestNearlyEqual(TEXT("Low g trigger resistance is featherweight (0.16)"), TriggerResistance, 0.16f, 0.05f);
		TestNearlyEqual(TEXT("Wind grip rumble is strong (0.40)"), LeftGripWind, 0.40f, 0.05f);
		TestNearlyEqual(TEXT("Bridge resonance hum is 0.75"), BridgeHum, 0.75f, 0.02f);
	}

	// -----------------------------------------------------------------------------------
	// 5. TEST SAVEGAME PERSISTENCE
	// -----------------------------------------------------------------------------------
	{
		UAshenScenario9SaveGameAdapter* SaveAdapter = NewObject<UAshenScenario9SaveGameAdapter>();
		SaveAdapter->PackageScenario9State(0.35f, 9200.0f, 4, 12);
		TestTrue(TEXT("HasSavedData is true"), SaveAdapter->HasSavedData());

		float RestoredG = 0.0f;
		float RestoredAlt = 0.0f;
		int32 RestoredBridges = 0;
		int32 RestoredAutomatons = 0;

		const bool bSuccess = SaveAdapter->RestoreScenario9State(RestoredG, RestoredAlt, RestoredBridges, RestoredAutomatons);
		TestTrue(TEXT("Restore succeeded"), bSuccess);
		TestNearlyEqual(TEXT("Restored gravity is 0.35g"), RestoredG, 0.35f, 0.01f);
		TestNearlyEqual(TEXT("Restored altitude is 9200uu"), RestoredAlt, 9200.0f, 1.0f);
		TestEqual(TEXT("Restored bridges is 4"), RestoredBridges, 4);
		TestEqual(TEXT("Restored automatons is 12"), RestoredAutomatons, 12);
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
