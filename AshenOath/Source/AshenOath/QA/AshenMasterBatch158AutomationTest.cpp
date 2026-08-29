// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Combat/AshenSeveranceTypes.h"
#include "Combat/AshenSeveranceDismembermentConvergenceSubsystem.h"
#include "Combat/AshenSeverancePlaneEvaluator.h"
#include "Combat/AshenAdrenalineSurgeEvaluator.h"
#include "Combat/AshenProceduralGoreDecalDirectorComponent.h"
#include "Combat/AshenSeveranceHapticBridge.h"
#include "Core/AshenSeveranceSaveGameAdapter.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch158AutomationTest,
	"AshenOath.Combat.MasterBatch158_SeveranceConvergence",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMasterBatch158AutomationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. TEST SEVERANCE PLANE EVALUATOR
	// -----------------------------------------------------------------------------------
	{
		UAshenSeverancePlaneEvaluator* PlaneEvaluator = NewObject<UAshenSeverancePlaneEvaluator>();

		const FVector HitLoc = FVector(100.0f, 0.0f, 150.0f);
		const FVector Trajectory = FVector(1.0f, 0.0f, 0.0f);

		// Decapitation Plane
		const FSeveranceSlicePlaneData HeadData = PlaneEvaluator->EvaluateSlicePlane(HitLoc, Trajectory, ESeveranceBoneTarget::Head);
		TestNearlyEqual(TEXT("Head slice normal Z is 1.0"), static_cast<float>(HeadData.PlaneNormal.Z), 1.0f, 0.01f);
		TestNearlyEqual(TEXT("Head slice impulse strength is 750"), HeadData.ImpulseStrength, 750.0f, 0.01f);

		// Torso Cleave Plane
		const FSeveranceSlicePlaneData TorsoData = PlaneEvaluator->EvaluateSlicePlane(HitLoc, Trajectory, ESeveranceBoneTarget::TorsoWaist);
		TestNearlyEqual(TEXT("Torso slice impulse strength is 1100"), TorsoData.ImpulseStrength, 1100.0f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 2. TEST ADRENALINE SURGE EVALUATOR
	// -----------------------------------------------------------------------------------
	{
		UAshenAdrenalineSurgeEvaluator* SurgeEvaluator = NewObject<UAshenAdrenalineSurgeEvaluator>();

		TestNearlyEqual(TEXT("Decapitation gives 35 adrenaline"), SurgeEvaluator->EvaluateAdrenalineGain(ESeveranceSeverityTier::Decapitation), 35.0f, 0.01f);
		TestNearlyEqual(TEXT("Total Bisection gives 40 adrenaline"), SurgeEvaluator->EvaluateAdrenalineGain(ESeveranceSeverityTier::TotalBisection), 40.0f, 0.01f);
		TestNearlyEqual(TEXT("Major Limb gives 25 adrenaline"), SurgeEvaluator->EvaluateAdrenalineGain(ESeveranceSeverityTier::MajorLimb), 25.0f, 0.01f);

		TestNearlyEqual(TEXT("50 adrenaline gives 25 stamina refill"), SurgeEvaluator->EvaluateStaminaRefill(50.0f), 25.0f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST PROCEDURAL GORE DECAL DIRECTOR
	// -----------------------------------------------------------------------------------
	{
		UAshenProceduralGoreDecalDirectorComponent* DecalDirector = NewObject<UAshenProceduralGoreDecalDirectorComponent>();

		const FTransform DecalTransform = DecalDirector->EvaluateDecalTransform(FVector::ZeroVector, FVector::UpVector, 1.50f);
		TestNearlyEqual(TEXT("Decal scale Y is 1.5 * 120 = 180"), static_cast<float>(DecalTransform.GetScale3D().Y), 180.0f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST DUALSENSE SEVERANCE HAPTICS
	// -----------------------------------------------------------------------------------
	{
		UAshenSeveranceHapticBridge* HapticBridge = NewObject<UAshenSeveranceHapticBridge>();
		float HeavyGain = 0.0f;
		float LightGain = 0.0f;

		// Decapitation: 0.95 heavy, 0.70 light
		HapticBridge->EvaluateSeveranceHaptics(ESeveranceSeverityTier::Decapitation, false, HeavyGain, LightGain);
		TestNearlyEqual(TEXT("Decapitation heavy gain is 0.95"), HeavyGain, 0.95f, 0.01f);
		TestNearlyEqual(TEXT("Decapitation light gain is 0.70"), LightGain, 0.70f, 0.01f);

		// Adrenaline Surging: 0.95 heavy, 0.80 light
		HapticBridge->EvaluateSeveranceHaptics(ESeveranceSeverityTier::MinorLimb, true, HeavyGain, LightGain);
		TestNearlyEqual(TEXT("Surge heavy gain is 0.95"), HeavyGain, 0.95f, 0.01f);
		TestNearlyEqual(TEXT("Surge light gain is 0.80"), LightGain, 0.80f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 5. TEST SAVEGAME PERSISTENCE
	// -----------------------------------------------------------------------------------
	{
		UAshenSeveranceSaveGameAdapter* SaveAdapter = NewObject<UAshenSeveranceSaveGameAdapter>();
		SaveAdapter->PackageSeveranceStats(42, 18, 1250.0f);
		TestTrue(TEXT("SaveData is true"), SaveAdapter->HasSavedData());

		int32 RestoredDecap = 0;
		int32 RestoredBisect = 0;
		float RestoredAdrenaline = 0.0f;

		const bool bSuccess = SaveAdapter->RestoreSeveranceStats(RestoredDecap, RestoredBisect, RestoredAdrenaline);
		TestTrue(TEXT("Restore succeeded"), bSuccess);
		TestEqual(TEXT("Decapitations restored"), RestoredDecap, 42);
		TestEqual(TEXT("Bisections restored"), RestoredBisect, 18);
		TestNearlyEqual(TEXT("Lifetime adrenaline restored"), RestoredAdrenaline, 1250.0f, 0.01f);
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
