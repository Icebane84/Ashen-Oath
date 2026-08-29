// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "World/AshenDestructionWeatherAITypes.h"
#include "World/AshenDestructionWeatherAIConvergenceSubsystem.h"
#include "World/AshenWeatherPerceptionClampEvaluator.h"
#include "World/AshenConductiveLightningArcEvaluator.h"
#include "World/AshenDestructionCoverDurabilityEvaluator.h"
#include "Combat/AshenDestructionWeatherAIHapticBridge.h"
#include "Core/AshenDestructionWeatherAISaveGameAdapter.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch152AutomationTest,
	"AshenOath.World.MasterBatch152_DestructionWeatherAIConvergence",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMasterBatch152AutomationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. TEST WEATHER PERCEPTION CLAMP EVALUATOR
	// -----------------------------------------------------------------------------------
	{
		UAshenWeatherPerceptionClampEvaluator* Evaluator = NewObject<UAshenWeatherPerceptionClampEvaluator>();

		// Clear daylight: 1500uu lock-on, 2000uu AI sight, 90 deg vision cone, 1.0x stealth
		TestNearlyEqual(TEXT("Clear daylight lock-on range is 1500uu"), Evaluator->EvaluateLockOnRangeClamp(EAtmosphericVisibilityTier::ClearDaylight), 1500.0f, 1.0f);
		TestNearlyEqual(TEXT("Clear daylight AI sight radius is 2000uu"), Evaluator->EvaluateAISightRadius(EAtmosphericVisibilityTier::ClearDaylight), 2000.0f, 1.0f);
		TestNearlyEqual(TEXT("Clear daylight AI vision cone is 90 deg"), Evaluator->EvaluateAIVisionConeDegrees(EAtmosphericVisibilityTier::ClearDaylight), 90.0f, 1.0f);
		TestNearlyEqual(TEXT("Clear daylight stealth multiplier is 1.0x"), Evaluator->EvaluateStealthAmbushMultiplier(EAtmosphericVisibilityTier::ClearDaylight), 1.00f, 0.01f);

		// Blizzard whiteout: 500uu lock-on, 600uu AI sight, 45 deg vision cone, 1.50x stealth
		TestNearlyEqual(TEXT("Blizzard whiteout lock-on range is 500uu"), Evaluator->EvaluateLockOnRangeClamp(EAtmosphericVisibilityTier::BlizzardWhiteout), 500.0f, 1.0f);
		TestNearlyEqual(TEXT("Blizzard whiteout AI sight radius is 600uu"), Evaluator->EvaluateAISightRadius(EAtmosphericVisibilityTier::BlizzardWhiteout), 600.0f, 1.0f);
		TestNearlyEqual(TEXT("Blizzard whiteout AI vision cone is 45 deg"), Evaluator->EvaluateAIVisionConeDegrees(EAtmosphericVisibilityTier::BlizzardWhiteout), 45.0f, 1.0f);
		TestNearlyEqual(TEXT("Blizzard whiteout stealth multiplier is 1.50x"), Evaluator->EvaluateStealthAmbushMultiplier(EAtmosphericVisibilityTier::BlizzardWhiteout), 1.50f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 2. TEST CONDUCTIVE LIGHTNING ARC EVALUATOR
	// -----------------------------------------------------------------------------------
	{
		UAshenConductiveLightningArcEvaluator* ArcEvaluator = NewObject<UAshenConductiveLightningArcEvaluator>();

		// Non-conductive dry stone: 0 damage, 0.0s paralysis
		TestFalse(TEXT("Dry stone is non-conductive"), ArcEvaluator->IsSurfaceConductive(EConductiveSurfaceType::NonConductiveStone));
		TestNearlyEqual(TEXT("Dry stone shock damage is 0"), ArcEvaluator->EvaluateChainShockDamage(EConductiveSurfaceType::NonConductiveStone), 0.0f, 0.01f);
		TestNearlyEqual(TEXT("Dry stone paralysis is 0.0s"), ArcEvaluator->EvaluateParalysisStaggerSeconds(EConductiveSurfaceType::NonConductiveStone), 0.0f, 0.01f);

		// Wet acid puddle: 350 damage, 1.2s paralysis
		TestTrue(TEXT("Wet acid puddle is conductive"), ArcEvaluator->IsSurfaceConductive(EConductiveSurfaceType::WetAcidPuddle));
		TestNearlyEqual(TEXT("Wet acid puddle shock damage is 350"), ArcEvaluator->EvaluateChainShockDamage(EConductiveSurfaceType::WetAcidPuddle), 350.0f, 0.01f);
		TestNearlyEqual(TEXT("Wet acid puddle paralysis is 1.2s"), ArcEvaluator->EvaluateParalysisStaggerSeconds(EConductiveSurfaceType::WetAcidPuddle), 1.20f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST COVER DURABILITY & SHRAPNEL
	// -----------------------------------------------------------------------------------
	{
		UAshenDestructionCoverDurabilityEvaluator* DurabilityEvaluator = NewObject<UAshenDestructionCoverDurabilityEvaluator>();

		const float RemainingHP = DurabilityEvaluator->EvaluateRemainingCoverHP(500.0f, 200.0f);
		TestNearlyEqual(TEXT("Remaining cover HP is 300"), RemainingHP, 300.0f, 0.01f);
		TestNearlyEqual(TEXT("Shrapnel explosion damage is 250"), DurabilityEvaluator->EvaluateShrapnelDamage(500.0f), 250.0f, 0.01f);
		TestNearlyEqual(TEXT("Shrapnel blast radius is 250uu"), DurabilityEvaluator->EvaluateShrapnelRadiusUU(), 250.0f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST DUALSENSE TACTICAL HAPTICS
	// -----------------------------------------------------------------------------------
	{
		UAshenDestructionWeatherAIHapticBridge* HapticBridge = NewObject<UAshenDestructionWeatherAIHapticBridge>();
		float HeavyPunch = 0.0f;
		float LightTingle = 0.0f;

		// Direct lightning strike: 0.95 heavy punch, 0.80 light tingle
		HapticBridge->EvaluateTacticalHaptics(true, false, false, HeavyPunch, LightTingle);
		TestNearlyEqual(TEXT("Direct lightning heavy punch is 0.95"), HeavyPunch, 0.95f, 0.01f);
		TestNearlyEqual(TEXT("Direct lightning light tingle is 0.80"), LightTingle, 0.80f, 0.01f);

		// Conductive arc chained: 0.40 heavy punch, 0.90 light tingle
		HapticBridge->EvaluateTacticalHaptics(false, true, false, HeavyPunch, LightTingle);
		TestNearlyEqual(TEXT("Conductive arc heavy punch is 0.40"), HeavyPunch, 0.40f, 0.01f);
		TestNearlyEqual(TEXT("Conductive arc light tingle is 0.90"), LightTingle, 0.90f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 5. TEST SAVEGAME PERSISTENCE
	// -----------------------------------------------------------------------------------
	{
		UAshenDestructionWeatherAISaveGameAdapter* SaveAdapter = NewObject<UAshenDestructionWeatherAISaveGameAdapter>();
		SaveAdapter->PackageTacticalState(EAtmosphericVisibilityTier::VolcanicAshStorm, 750.0f, 4);
		TestTrue(TEXT("SaveData is true"), SaveAdapter->HasSavedData());

		EAtmosphericVisibilityTier RestoredTier = EAtmosphericVisibilityTier::ClearDaylight;
		float RestoredLockOn = 0.0f;
		int32 RestoredObstacles = 0;

		const bool bSuccess = SaveAdapter->RestoreTacticalState(RestoredTier, RestoredLockOn, RestoredObstacles);
		TestTrue(TEXT("Restore succeeded"), bSuccess);
		TestTrue(TEXT("Restored tier is VolcanicAshStorm"), RestoredTier == EAtmosphericVisibilityTier::VolcanicAshStorm);
		TestNearlyEqual(TEXT("Restored lock-on is 750uu"), RestoredLockOn, 750.0f, 1.0f);
		TestEqual(TEXT("Restored obstacle count is 4"), RestoredObstacles, 4);
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
