// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Combat/AshenKineticBerserkTypes.h"
#include "Combat/AshenKineticBerserkSubsystem.h"
#include "Combat/AshenAngularCounterComponent.h"
#include "Audio/AshenDynamicDebrisOcclusionAudioLinker.h"
#include "Combat/AshenMassKineticNiagaraBridgeComponent.h"
#include "Combat/AshenBerserkTargetTrackingComponent.h"
#include "Core/AshenKineticBerserkSaveGameAdapter.h"
#include "Combat/AshenKineticBerserkHapticBridge.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch131AutomationTest,
	"AshenOath.Combat.MasterBatch131_PRS001KineticBerserkConvergence",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMasterBatch131AutomationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. TEST DYNAMIC DEBRIS AUDIO OCCLUSION LPF CUTOFF
	// -----------------------------------------------------------------------------------
	{
		// 0 Rubble chunks -> 20,000 Hz (Unoccluded)
		const float CleanCutoff = UAshenDynamicDebrisOcclusionAudioLinker::CalculateDebrisLowPassCutoff(0);
		TestNearlyEqual(TEXT("0 Rubble chunks produces 20,000 Hz"), CleanCutoff, 20000.0f, 1.0f);
		TestTrue(TEXT("0 Rubble chunks is Unoccluded state"), UAshenDynamicDebrisOcclusionAudioLinker::EvaluateDebrisOcclusionState(0) == EAshenDebrisOcclusionState::Unoccluded);

		// 6 Rubble chunks (Max) -> 400 Hz (Muffled Floor)
		const float MuffledCutoff = UAshenDynamicDebrisOcclusionAudioLinker::CalculateDebrisLowPassCutoff(6);
		TestNearlyEqual(TEXT("6 Rubble chunks produces 400 Hz"), MuffledCutoff, 400.0f, 1.0f);
		TestTrue(TEXT("6 Rubble chunks is BuriedUnderRubble state"), UAshenDynamicDebrisOcclusionAudioLinker::EvaluateDebrisOcclusionState(6) == EAshenDebrisOcclusionState::BuriedUnderRubble);

		// 2 Rubble chunks -> Partial Debris
		TestTrue(TEXT("2 Rubble chunks is PartialDebris state"), UAshenDynamicDebrisOcclusionAudioLinker::EvaluateDebrisOcclusionState(2) == EAshenDebrisOcclusionState::PartialDebris);
	}

	// -----------------------------------------------------------------------------------
	// 2. TEST GEOMETRY BACK-FACE EXIT RAYCAST TRACE
	// -----------------------------------------------------------------------------------
	{
		UAshenMassKineticNiagaraBridgeComponent* NiagaraBridge = NewObject<UAshenMassKineticNiagaraBridgeComponent>();

		const FVector EntryPoint = FVector(100.0f, 0.0f, 50.0f);
		const FVector Trajectory = FVector(1.0f, 0.0f, 0.0f);
		const float Depth = 40.0f;
		const float Joules = 5200.0f;

		const FAshenNiagaraShearTraceData TraceData = NiagaraBridge->ComputeExitShearVector(EntryPoint, Trajectory, Depth, Joules);

		TestEqual(TEXT("Entry coordinate matches"), TraceData.BladeEntryCoordinate, EntryPoint);
		TestEqual(TEXT("Exit coordinate is 140, 0, 50"), TraceData.BladeExitCoordinate, FVector(140.0f, 0.0f, 50.0f));
		TestEqual(TEXT("Shear trajectory matches forward"), TraceData.ExitShearTrajectory, FVector(1.0f, 0.0f, 0.0f));
		TestNearlyEqual(TEXT("Kinetic Joules match"), TraceData.KineticEnergyJoules, 5200.0f, 0.1f);
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST TARGET TRACKING CAMERA LOCK EVALUATION
	// -----------------------------------------------------------------------------------
	{
		UAshenBerserkTargetTrackingComponent* TrackingComp = NewObject<UAshenBerserkTargetTrackingComponent>();

		const FVector PlayerLoc = FVector(0.0f, 0.0f, 0.0f);
		const FRotator PlayerRot = FRotator(0.0f, 0.0f, 0.0f);
		const FVector TargetLoc = FVector(500.0f, 500.0f, 0.0f);

		// In Manual Free Look, rotation should remain unchanged
		TrackingComp->SetTrackingMode(EAshenTargetTrackingMode::ManualFreeLook);
		const FRotator ManualRot = TrackingComp->EvaluateTargetTrackingRotation(PlayerLoc, PlayerRot, TargetLoc, 10.0f, 0.016f);
		TestEqual(TEXT("Manual mode preserves current rotation"), ManualRot, PlayerRot);

		// In Automated Sphere Lock, rotation should interpolate towards target (45° yaw)
		TrackingComp->SetTrackingMode(EAshenTargetTrackingMode::AutomatedSphereLock);
		const FRotator AutoRot = TrackingComp->EvaluateTargetTrackingRotation(PlayerLoc, PlayerRot, TargetLoc, 100.0f, 1.0f);
		TestNearlyEqual(TEXT("Auto mode rotates towards target at ~45° yaw"), static_cast<float>(AutoRot.Yaw), 45.0f, 1.0f);
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST DUALSENSE KINETIC HAPTICS
	// -----------------------------------------------------------------------------------
	{
		UAshenKineticBerserkHapticBridge* HapticBridge = NewObject<UAshenKineticBerserkHapticBridge>();

		float TriggerRes = 0.0f;
		float GripVibe = 0.0f;

		// When cutting dense stone (play rate = 0.08x floor), resistance should be ~0.92
		HapticBridge->EvaluateKineticHaptics(5000.0f, 0.08f, TriggerRes, GripVibe);
		TestNearlyEqual(TEXT("Dense cutting trigger resistance is 0.92"), TriggerRes, 0.92f, 0.01f);
		TestNearlyEqual(TEXT("5000J grip vibration is 0.50"), GripVibe, 0.50f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 5. TEST SAVEGAME STATS PERSISTENCE
	// -----------------------------------------------------------------------------------
	{
		UAshenKineticBerserkSaveGameAdapter* SaveAdapter = NewObject<UAshenKineticBerserkSaveGameAdapter>();

		SaveAdapter->PackageKineticStats(14, 6800.0f, 8);
		TestTrue(TEXT("HasSavedData is true"), SaveAdapter->HasSavedData());

		int32 Ripostes = 0;
		float Joules = 0.0f;
		int32 Fractures = 0;
		const bool bSuccess = SaveAdapter->RestoreKineticStats(Ripostes, Joules, Fractures);

		TestTrue(TEXT("Restore succeeded"), bSuccess);
		TestEqual(TEXT("Ripostes count is 14"), Ripostes, 14);
		TestNearlyEqual(TEXT("Max Joules is 6800.0f"), Joules, 6800.0f, 0.1f);
		TestEqual(TEXT("Fractures count is 8"), Fractures, 8);
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
