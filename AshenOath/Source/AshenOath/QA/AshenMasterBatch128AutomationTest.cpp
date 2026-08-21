// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Scenarios/AshenScenario2SentinelsGambitTypes.h"
#include "Scenarios/AshenScenario2MissionSubsystem.h"
#include "Scenarios/AshenGarrettTrapGridEvaluatorComponent.h"
#include "Scenarios/AshenPathfindingDisruptionEvaluatorComponent.h"
#include "Scenarios/AshenScenario2HapticBridge.h"
#include "Core/AshenScenario2SaveGameAdapter.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch128AutomationTest,
	"AshenOath.Scenarios.MasterBatch128_Scenario2SentinelsGambit",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMasterBatch128AutomationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. TEST TRAP REGISTRATION & PLACEMENT TRACKING
	// -----------------------------------------------------------------------------------
	{
		UAshenScenario2MissionSubsystem* MissionSubsystem = NewObject<UAshenScenario2MissionSubsystem>();

		FGarrettTrapPlacementData Trap;
		Trap.TrapId = FName(TEXT("Trap_TensionWire_Choke1"));
		Trap.TrapType = EGarrettTrapType::TensionWireSnare;
		Trap.WorldLocation = FVector(100.0f, 200.0f, 0.0f);
		Trap.DetonationRadiusCentimeters = 350.0f;
		Trap.bIsArmed = true;

		const bool bRegistered = MissionSubsystem->RegisterTrap(Trap);
		TestTrue(TEXT("Trap successfully registered"), bRegistered);
		TestEqual(TEXT("Deployed trap count is 1"), MissionSubsystem->GetDeployedTrapCount(), 1);

		// Duplicate registration rejected
		const bool bDuplicate = MissionSubsystem->RegisterTrap(Trap);
		TestFalse(TEXT("Duplicate trap registration rejected"), bDuplicate);
	}

	// -----------------------------------------------------------------------------------
	// 2. TEST AI PATHFINDING DISRUPTION & LAW-001 CIRCUIT BREAKER
	// -----------------------------------------------------------------------------------
	{
		UAshenPathfindingDisruptionEvaluatorComponent* DisruptionEvaluator = NewObject<UAshenPathfindingDisruptionEvaluatorComponent>();

		// Utility >= 0.70 -> Normal
		TestEqual(TEXT("Utility 0.85 is Normal Navigation"), DisruptionEvaluator->EvaluateDisruptionTier(0.85f), EPathfindingDisruptionTier::NormalNavigation);

		// Utility 0.50 -> Degraded Routing
		TestEqual(TEXT("Utility 0.50 is Degraded Routing"), DisruptionEvaluator->EvaluateDisruptionTier(0.50f), EPathfindingDisruptionTier::DegradedRouting);

		// Utility < 0.15 -> LAW-001 Circuit Breaker Tripped (Failed Recovery)
		TestEqual(TEXT("Utility 0.10 trips LAW-001 Circuit Breaker"), DisruptionEvaluator->EvaluateDisruptionTier(0.10f), EPathfindingDisruptionTier::CircuitBreakerTripped);

		// Test degradation: 1.0 base - (3 traps * 0.25) = 0.25 (Degraded)
		const float Degraded = DisruptionEvaluator->EvaluateDegradedUtility(1.0f, 3);
		TestNearlyEqual(TEXT("Utility with 3 traps is 0.25"), Degraded, 0.25f, 0.01f);

		// Test degradation: 1.0 base - (4 traps * 0.25) = 0.0 (Trips Circuit Breaker)
		const float Tripped = DisruptionEvaluator->EvaluateDegradedUtility(1.0f, 4);
		TestNearlyEqual(TEXT("Utility with 4 traps is 0.0"), Tripped, 0.0f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST TRAP PROXIMITY TRIGGER
	// -----------------------------------------------------------------------------------
	{
		UAshenGarrettTrapGridEvaluatorComponent* TrapGrid = NewObject<UAshenGarrettTrapGridEvaluatorComponent>();

		const FVector TrapLoc(0.0f, 0.0f, 0.0f);
		const FVector InsideLoc(100.0f, 100.0f, 0.0f); // ~141cm (< 350cm)
		const FVector OutsideLoc(400.0f, 0.0f, 0.0f);  // 400cm (> 350cm)

		TestTrue(TEXT("Enemy inside radius triggers trap"), TrapGrid->EvaluateTrapTrigger(InsideLoc, TrapLoc, 350.0f));
		TestFalse(TEXT("Enemy outside radius does not trigger"), TrapGrid->EvaluateTrapTrigger(OutsideLoc, TrapLoc, 350.0f));
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST DUAL-CHANNEL DUALSENSE HAPTICS
	// -----------------------------------------------------------------------------------
	{
		UAshenScenario2HapticBridge* HapticBridge = NewObject<UAshenScenario2HapticBridge>();

		float LeftRumble = 0.0f;
		float RightSpark = 0.0f;

		// High Corruption (0.80), Phosphor flare active
		HapticBridge->EvaluateDualChannelHaptics(0.80f, true, LeftRumble, RightSpark);
		TestNearlyEqual(TEXT("Left rumble is 0.68 (0.80 * 0.85)"), LeftRumble, 0.68f, 0.01f);
		TestNearlyEqual(TEXT("Right spark is 0.90 (Active flare)"), RightSpark, 0.90f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 5. TEST SAVEGAME PERSISTENCE
	// -----------------------------------------------------------------------------------
	{
		UAshenScenario2SaveGameAdapter* SaveAdapter = NewObject<UAshenScenario2SaveGameAdapter>();

		SaveAdapter->PackageScenario2State(true, 5, TEXT("Calculated_Pragmatic"));
		TestTrue(TEXT("HasSavedData is true"), SaveAdapter->HasSavedData());

		bool bSilent = false;
		int32 Funneled = 0;
		FString Profile;
		const bool bSuccess = SaveAdapter->RestoreScenario2State(bSilent, Funneled, Profile);

		TestTrue(TEXT("Restore succeeded"), bSuccess);
		TestTrue(TEXT("bSilent is true"), bSilent);
		TestEqual(TEXT("Funneled count is 5"), Funneled, 5);
		TestEqual(TEXT("Profile is Calculated_Pragmatic"), Profile, FString(TEXT("Calculated_Pragmatic")));
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
