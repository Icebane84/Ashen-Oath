// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Combat/AshenMassKineticTypes.h"
#include "Combat/AshenMassKineticCleaveComponent.h"
#include "Combat/AshenWeaponResistanceWarperComponent.h"
#include "Combat/AshenCameraResistanceDilationComponent.h"
#include "Combat/AshenKineticDeflectionParryGASAbility.h"
#include "Core/AshenKineticCombatSaveGameAdapter.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch119AutomationTest,
	"AshenOath.Combat.MasterBatch119_MassKineticCleave",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMasterBatch119AutomationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. TEST MASS KINETIC CLEAVE ENERGY CALCULATION (DUAL STANCE)
	// -----------------------------------------------------------------------------------
	{
		UAshenMassKineticCleaveComponent* CleaveComp = NewObject<UAshenMassKineticCleaveComponent>();

		// Light Mode: 45kg @ 10 m/s -> Ek = 0.5 * 45 * 100 = 2250 Joules (Structural Crack)
		const FKineticSwingSnapshot LightSnap = CleaveComp->CalculateKineticPayload(
			EKineticCleaveStance::LightInnerFlame, 10.0f);
		TestNearlyEqual(TEXT("Light Mode kinetic energy is 2250 Joules"), LightSnap.KineticEnergyJoules, 2250.0f, 1.0f);
		TestEqual(TEXT("Light Mode tier is Structural Crack"), LightSnap.FractureTier, EStructuralFractureTier::StructuralCrack);

		// Dark Mode: 180kg @ 10 m/s -> Ek = 0.5 * 180 * 100 * 2.5 = 22,500 Joules (Catastrophic Cleave)
		const FKineticSwingSnapshot DarkSnap = CleaveComp->CalculateKineticPayload(
			EKineticCleaveStance::DarkShadowUnleashed, 10.0f);
		TestNearlyEqual(TEXT("Dark Mode kinetic energy is 22,500 Joules"), DarkSnap.KineticEnergyJoules, 22500.0f, 1.0f);
		TestEqual(TEXT("Dark Mode tier is Catastrophic Cleave"), DarkSnap.FractureTier, EStructuralFractureTier::CatastrophicCleave);
	}

	// -----------------------------------------------------------------------------------
	// 2. TEST VOLUME RESISTANCE WARPER (ANIMATION SLOWDOWN)
	// -----------------------------------------------------------------------------------
	{
		UAshenWeaponResistanceWarperComponent* Warper = NewObject<UAshenWeaponResistanceWarperComponent>();

		// 0 volume -> 1.0 play rate
		const float RateZero = Warper->CalculatePlayRateForVolume(0.0f);
		TestNearlyEqual(TEXT("Zero volume gives full play rate"), RateZero, 1.0f, 0.01f);

		// Max volume (10,000 cm3) -> clamped down to 0.08 floor
		const float RateMax = Warper->CalculatePlayRateForVolume(10000.0f);
		TestNearlyEqual(TEXT("Heavy volume clamps play rate to 0.08 floor"), RateMax, 0.08f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST CAMERA RESISTANCE DILATION (FOV COMPRESSION)
	// -----------------------------------------------------------------------------------
	{
		UAshenCameraResistanceDilationComponent* Dilation = NewObject<UAshenCameraResistanceDilationComponent>();

		// 0 volume -> 90 deg FOV
		const float FOVZero = Dilation->CalculateCompressedFOV(0.0f);
		TestNearlyEqual(TEXT("Zero volume gives 90 deg FOV"), FOVZero, 90.0f, 0.1f);

		// Max volume -> 76 deg FOV
		const float FOVMax = Dilation->CalculateCompressedFOV(10000.0f);
		TestNearlyEqual(TEXT("Max volume compresses FOV to 76 deg"), FOVMax, 76.0f, 0.1f);
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST KINETIC DEFLECTION PARRY TIMING (120ms WINDOW)
	// -----------------------------------------------------------------------------------
	{
		UAshenKineticDeflectionParryGASAbility* ParryAbility = NewObject<UAshenKineticDeflectionParryGASAbility>();

		// 0.08s -> within 120ms window -> Success
		TestTrue(TEXT("0.08s delta is within deflection window"), ParryAbility->EvaluateDeflectionSuccess(0.08f));

		// 0.15s -> beyond 120ms window -> Fail
		TestFalse(TEXT("0.15s delta misses deflection window"), ParryAbility->EvaluateDeflectionSuccess(0.15f));
	}

	// -----------------------------------------------------------------------------------
	// 5. TEST KINETIC SAVEGAME ADAPTER
	// -----------------------------------------------------------------------------------
	{
		UAshenKineticCombatSaveGameAdapter* SaveAdapter = NewObject<UAshenKineticCombatSaveGameAdapter>();

		SaveAdapter->PackageKineticData(12, 22500.0f, 45);
		TestTrue(TEXT("HasSavedData is true"), SaveAdapter->HasSavedData());

		int32 RestoredPillars = 0;
		float RestoredPeakJoules = 0.0f;
		int32 RestoredParries = 0;
		const bool bSuccess = SaveAdapter->RestoreKineticData(RestoredPillars, RestoredPeakJoules, RestoredParries);

		TestTrue(TEXT("Restore succeeded"), bSuccess);
		TestEqual(TEXT("Destroyed pillars restored"), RestoredPillars, 12);
		TestNearlyEqual(TEXT("Peak Joules restored"), RestoredPeakJoules, 22500.0f, 1.0f);
		TestEqual(TEXT("Parries restored"), RestoredParries, 45);
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
